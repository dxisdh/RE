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
- Chương trình lấy trường NtGlobalFlag để check xem có đang debug hay không, nếu có thì được set giá trị bằng 0x70. Ta sẽ đi theo đường màu xanh, lúc đó dl mang giá trị 0 và được sử dụng tại hàm sub_92050. Hàm này chỉ có chức năng tạo ra 1 const data
````
while ( 2 )
  {
    switch ( dword_4532C8[v3] )
    {
      case 1:
        v4 = const[v3];
        v5 = this[table[v3]];
        v24 = NtCurrentPeb()->NtGlobalFlag & 0x70;
        v6 = gen_const(v24 == 112, (int)v25, v4);
        v7 = v26;
        if ( v26 >= 256 )
          v7 = 0;
        v26 = v7 + 1;
        v2 = byte_45329F[v7 + 1] == (char)(v5 ^ v6);
        goto LABEL_9;
````
- Ta thấy gen_const xong sẽ xor với byte_45329F sẽ ra input đúng
### Case 2:
- Chương trình kiểm tra debugger bằng trường Flags có offset 0xC
- Nếu có debugger thì v11 = 0x40000062
- Giá trị của dl bằng 1 khi không debug
### Case 3:
- Chương trình kiểm tra debugger bằng trường Flags có offset 0x10
- Nếu có debugger thì v6 = 0x40000060
- Giá trị của dl bằng 1 khi không debug
### Case 4:
- Nếu cờ HEAP_TAIL_CHECKING_ENABLED được set trong NtGlobalFlag, cụm 0xABABABAB sẽ được thêm vào cuối khối heap
- Nếu như có 8 khối AB thì sẽ trả về giá trị 1 (tức có debug)
- Giá trị của dl bằng 0 khi không debug
### Case 5:
- Chương trình kiểm tra xem có process của debugger hay không
- Giá trị của dl bằng 1 khi không debug
### Case 6:
````
bool __usercall sub_451AA0@<al>(char a1@<dl>, int a2@<ecx>, int a3)
{
  struct _LIST_ENTRY *v5; // eax
  int (__stdcall *v6)(int); // esi
  char v7; // bl
  char v8; // al
  char v9; // al

  v5 = resolve_func((void *)0x2489AAB);
  v6 = (int (__stdcall *)(int))resolve_final((int)v5, 838910877);
  v7 = v6(1);
  v8 = v6(1);
  if ( byte_4555B8 )
  {
    if ( v7 == v8 )
      goto LABEL_3;
  }
  else if ( v7 != v8 )
  {
LABEL_3:
    v9 = gen_char(1, a2, a3);
    byte_4555B8 = 1;
    goto LABEL_6;
  }
  v9 = gen_char(0, a2, a3);
LABEL_6:
  if ( *(int *)(a2 + 556) >= 256 )
    *(_DWORD *)(a2 + 556) = 0;
  ++*(_DWORD *)(a2 + 556);
  return byte_45329F[*(_DWORD *)(a2 + 556)] == (char)(a1 ^ v9);
}
````
- Gọi v6 (tức BlockInput) 2 lần với đầu vào là 1. v7 sẽ trả về giá trị true còn nếu có debug thì v8 sẽ có giá trị trả về là true nên ta sẽ bypass bằng cách cho chạy BlockInput 2 lần
- Giá trị của dl bằng 1 khi không debug
### Case 7:
- Làm tương tự hàm TlsCallback ta thấy giá trị của EAX được trả về là hàm NtQueryInformationProcess()
- Giá trị của dl bằng 1 khi không debug
# Code solve
- Ta thấy hàm gen_const nhận 3 tham số:
  - Tham số đầu tiên là 1 hoặc 0 (giá trị dl)
  - Tham số thứ hai là hàm dùng data thay đổi dữ liệu ở TlsCallback
  - Tham số thứ ba là g_const
- Mình sẽ dùng code của hàm gen_const và code lại các switch case:
````
#include<stdio.h>
#define _DWORD unsigned __int32
#define _WORD unsigned __int16
char gen_const(char a1, unsigned __int8 *a2, int a3)
{
  int v4; // esi
  char v6; // bl
  int v7; // ecx
  unsigned __int16 v8; // dx
  unsigned int v9; // edx
  char v10; // cl
  unsigned int v11; // edx
  unsigned __int8 v12; // al
  bool v13; // zf
  unsigned __int8 *v14; // ecx
  int v15; // esi
  char v16; // dl
  int v18; // [esp+14h] [ebp+8h]

  v4 = a3 - 1;
  v18 = 171;
  v6 = 0;
  do
  {
    if ( v4 <= 5 )
    {
      if ( *(_DWORD *)&a2[4 * v4 + 16] )
        v8 = *(_WORD *)&a2[4 * v4 + 16];
      else
        v8 = *(_WORD *)&a2[4 * v4];
      v7 = (v8 >> 1) | (unsigned __int16)(((unsigned __int16)(32 * v8) ^ (v8 ^ (unsigned __int16)(4 * (v8 ^ (2 * v8)))) & 0xFFE0) << 10);
      *(_DWORD *)&a2[4 * v4 + 16] = v7;
    }
    else
    {
      v7 = 0;
    }
    v9 = v7 & 0x7FF;
    v10 = v7 & 7;
    v11 = v9 >> 3;
    if ( a1 )
      v12 = a2[v11 + 44];
    else
      v12 = ~a2[v11 + 44];
    v13 = v18-- == 1;
    a2[v11 + 44] = v12 ^ (1 << v10);
  }
  while ( !v13 );
  v14 = a2 + 46;
  v15 = 64;
  do
  {
    v16 = *(v14 - 2);
    v14 += 4;
    v6 ^= *(v14 - 4) ^ *(v14 - 3) ^ *(v14 - 5) ^ v16;
    --v15;
  }
  while ( v15 );
  return v6;
}

int main() {
	unsigned __int32 table[] = {9, 18, 15, 3, 4, 23, 6, 7, 8, 22, 10, 11, 33, 13, 14, 27, 16, 37, 17, 19, 20, 21, 5, 34, 24, 25, 26, 2, 12, 29, 30, 31, 32, 28, 0, 35, 36, 1};
	unsigned __int32 g_const[] = {1, 3, 1, 1, 2, 1, 3, 1, 2, 2, 4, 4, 1, 3, 4, 4, 4, 1, 2, 1, 4, 1, 4, 3, 1, 2, 4, 4, 2, 2, 1, 3, 4, 2, 1, 2, 2, 3};
	unsigned __int8 default_const[] = {54,236,0,0,54,237,0,0,54,187,0,0,54,140,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned __int8 cipher[] = {14, 235, 243, 246, 209, 107, 167, 143, 61, 145, 133, 43, 134, 167, 107, 219, 123, 110, 137, 137,  24, 149, 103, 202, 95, 226, 84, 14, 211, 62,  32,  90, 126, 212, 184, 16, 194, 183};
	unsigned __int32 program[] ={6, 1, 7, 1, 3, 2, 4, 3, 6, 3, 7, 6, 1, 4, 7, 4, 1, 5, 7, 6, 7, 5, 6, 4, 5, 1, 7, 5, 2, 3, 1, 2, 3, 2, 1, 6, 2, 4};
	unsigned char tmp;
  	unsigned char flag[40];
 
	for(int i=0;i<38;i++){
		switch(program[i]){
			case 1:
				tmp = gen_const(0,default_const,g_const[i]);
				flag[table[i]] = cipher[i]^tmp;
				break;
			case 2:
				tmp = gen_const(1,default_const,g_const[i]);
				flag[table[i]] = cipher[i]^tmp;
				break;
			case 3:
				tmp = gen_const(1,default_const,g_const[i]);
				flag[table[i]] = cipher[i]^tmp;
				break;
			case 4:
				tmp = gen_const(0,default_const,g_const[i]);
				flag[table[i]] = cipher[i]^tmp;
				break;
			case 5:
				tmp = gen_const(0,default_const,g_const[i]);
				flag[table[i]] = cipher[i]^tmp;
				break;
			case 6:
				tmp = gen_const(1,default_const,g_const[i]);
				flag[table[i]] = cipher[i]^tmp;
				break;
			case 7:
				tmp = gen_const(1,default_const,g_const[i]);
				flag[table[i]] = cipher[i]^tmp;
				break;
			default:
				break;
				
		}
	}
	printf("%s",flag);
	return 1;
}
````
- Chạy đoạn code trên ta sẽ nhận được key: I_10v3-y0U__wh3n Y0u=c411..M3 Senor1t4
