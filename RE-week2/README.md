# Phân tích
- Ta nhận được 1 file PE32 và được yêu cầu phải chạy với quyền Administrator
- Chạy thử chương trình thì ta thấy chương trình yêu cầu ta nhập key, nếu đúng thì sẽ nhận được flag
## Hàm TlsCallback
- Ta thấy rằng sau 2 lệnh gọi hàm với hằng số tương ứng thì sẽ trả lại địa chỉ gọi hàm nào đó, nên ta sẽ đặt breakpoint tại 2 lệnh call để xem có gì hay không:
- Chạy thử đến 2 breakpoint thì ta thấy giá trị của EAX được trả về là hàm NtQueryInformationProcess()
- Khi debug ta thấy vùng nhớ unk_455018 + 10 sẽ mang giá trị 74h, đổi tên sang g_data để xem nó làm gì
- Ta có hàm WinMain:
````
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  HACCEL v4; // esi
  HANDLE CurrentProcess; // eax
  HWND Window; // eax
  HWND v7; // esi
  struct tagMSG Msg; // [esp+8h] [ebp-2Ch] BYREF
  HANDLE TokenHandle; // [esp+24h] [ebp-10h] BYREF
  DWORD ReturnLength; // [esp+28h] [ebp-Ch] BYREF
  HACCEL TokenInformation; // [esp+2Ch] [ebp-8h] BYREF

  v4 = 0;
  TokenHandle = 0;
  CurrentProcess = GetCurrentProcess();
  if ( OpenProcessToken(CurrentProcess, 8u, &TokenHandle) )
  {
    ReturnLength = 4;
    if ( GetTokenInformation(TokenHandle, TokenElevation, &TokenInformation, 4u, &ReturnLength) )
      v4 = TokenInformation;
  }
  if ( TokenHandle )
    CloseHandle(TokenHandle);
  if ( !v4 )
  {
    MessageBoxA(0, "Please run the program with administrator right", "Warning", 0);
    exit(1);
  }
  LoadStringW(hInstance, 0x67u, &WindowName, 100);
  LoadStringW(hInstance, 0x6Du, &ClassName, 100);
  sub_451260(hInstance);
  ::hInstance = hInstance;
  Window = CreateWindowExW(0, &ClassName, &WindowName, 0xCF0000u, 0x80000000, 0, 0x80000000, 0, 0, 0, hInstance, 0);
  v7 = Window;
  if ( !Window )
    return 0;
  ShowWindow(Window, nShowCmd);
  UpdateWindow(v7);
  TokenInformation = LoadAcceleratorsW(hInstance, (LPCWSTR)0x6D);
  while ( GetMessageW(&Msg, 0, 0, 0) )
  {
    if ( !TranslateAcceleratorW(Msg.hwnd, TokenInformation, &Msg) )
    {
      TranslateMessage(&Msg);
      DispatchMessageW(&Msg);
    }
  }
  return Msg.wParam;
}
````
- Hàm WinMain gọi CreateWindowExW vậy nên luồng chính sẽ nằm ở hInstance mà hInstance được khởi tạo từ hàm sub_451260:
````
ATOM __thiscall sub_451260(HINSTANCE hInstance)
{
  WNDCLASSEXW v2; // [esp+0h] [ebp-34h] BYREF

  v2.cbSize = 48;
  v2.style = 3;
  v2.lpfnWndProc = sub_451350;
  v2.cbClsExtra = 0;
  v2.cbWndExtra = 0;
  v2.hInstance = hInstance;
  v2.hIcon = LoadIconW(hInstance, (LPCWSTR)0x6B);
  v2.hCursor = LoadCursorW(0, (LPCWSTR)0x7F00);
  v2.hbrBackground = (HBRUSH)6;
  v2.lpszMenuName = (LPCWSTR)109;
  v2.lpszClassName = &ClassName;
  v2.hIconSm = LoadIconW(v2.hInstance, (LPCWSTR)0x6C);
  return RegisterClassExW(&v2);
}
````
- Luồng chính sẽ nằm tại hàm sub_451350:
````
LRESULT __stdcall sub_451350(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  const CHAR *v5; // [esp-Ch] [ebp-258h]
  DWORD pdwDataLen; // [esp+0h] [ebp-24Ch] BYREF
  struct tagPAINTSTRUCT Paint; // [esp+4h] [ebp-248h] BYREF
  __int128 v8[2]; // [esp+44h] [ebp-208h] BYREF
  __int128 v9; // [esp+64h] [ebp-1E8h]
  char v10[208]; // [esp+74h] [ebp-1D8h] BYREF
  CHAR String[260]; // [esp+144h] [ebp-108h] BYREF

  v8[0] = xmmword_4538D0;
  v8[1] = xmmword_4538E0;
  v9 = xmmword_4538F0;
  memset(v10, 0, sizeof(v10));
  pdwDataLen = 48;
  if ( Msg <= 15 )
  {
    switch ( Msg )
    {
      case 15u:
        BeginPaint(hWnd, &Paint);
        EndPaint(hWnd, &Paint);
        return 0;
      case 1u:
        sub_4512F0(hWnd);
        return 0;
      case 2u:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hWnd, Msg, wParam, lParam);
  }
  if ( Msg != 273 )
    return DefWindowProcW(hWnd, Msg, wParam, lParam);
  switch ( (unsigned __int16)wParam )
  {
    case 4u:
      GetWindowTextA(::hWnd, String, 256);
      if ( check(String) )
      {
        sub_451000((BYTE *)String, (BYTE *)v8, &pdwDataLen);
        if ( pdwDataLen >= 46 )
        {
          BYTE14(v9) = 0;
          MessageBoxA(0, (LPCSTR)v8, "OK", 0);
          return 0;
        }
        v5 = "Wrong";
      }
      else
      {
        v5 = "Wrong check fail";
      }
      MessageBoxA(0, "oh, no", v5, 0);
      return 0;
    case 0x68u:
      DialogBoxParamW(hInstance, (LPCWSTR)0x67, hWnd, DialogFunc, 0);
      return 0;
    case 0x69u:
      DestroyWindow(hWnd);
      return 0;
    default:
      return DefWindowProcW(hWnd, 0x111u, wParam, lParam);
  }
}
````
## Phân tích hàm check
Ta thấy trong switch case sẽ kiểm tra từng case, và mỗi case đều dùng anti-debug và xử lí dữ liệu liên quan tới 2 biến dword_703360 và dword_7033F8
### Case 1:
- Chương trình lấy trường NtGlobalFlag để check xem có đang debug hay không, nếu có thì được set giá trị bằng 0x70. Ta sẽ đi theo đường màu xanh, lúc đó dl mang giá trị 0 và được sử dụng tại hàm sub_92050
