## Phân tích
Ta nhận được 1 file PE32, chạy thử chương trình thì ta thấy chương trình cần nhập password và nếu đúng thì sẽ hiện ra flag:
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/4.png>

Sử dụng IDA để đọc pseudocode:
````
int __cdecl main(int argc, const char **argv, const char **envp)
{
  char v4; // [esp+0h] [ebp-2CCh]
  char v5; // [esp+0h] [ebp-2CCh]
  char v6; // [esp+0h] [ebp-2CCh]
  char Format[160]; // [esp+8h] [ebp-2C4h] BYREF
  char pass; // [esp+A8h] [ebp-224h] BYREF
  char v9[299]; // [esp+A9h] [ebp-223h] BYREF
  char key[200]; // [esp+1D4h] [ebp-F8h] BYREF
  void *v11; // [esp+29Ch] [ebp-30h]
  int flag_len; // [esp+2A0h] [ebp-2Ch]
  int v13; // [esp+2A4h] [ebp-28h]
  char *v14; // [esp+2A8h] [ebp-24h]
  int v15; // [esp+2ACh] [ebp-20h]
  char *v16; // [esp+2B0h] [ebp-1Ch]
  int tmp_pass_len; // [esp+2B4h] [ebp-18h]
  int v18; // [esp+2B8h] [ebp-14h]
  char *v19; // [esp+2BCh] [ebp-10h]
  char *p_pass; // [esp+2C0h] [ebp-Ch]
  int i; // [esp+2C8h] [ebp-4h]

  pass = 0;
  memset(v9, 0, sizeof(v9));
  flag_len = 335;
  memset(key, 0, sizeof(key));
  strcpy(
    Format,
    "Do you remember the good old days?! I don't know how about you,but I don't. Please help me to recover my memory, it'"
    "s password protected, and that's sad :(\n");
  v11 = &unk_344BE8;
  sub_341560(Format, v4);
  sub_341560("Enter password: ", v5);
  sub_3414D0("%300[^\n]s", (char)&pass);
  p_pass = &pass;
  v16 = v9;
  p_pass += strlen(p_pass);
  v15 = ++p_pass - v9;
  tmp_pass_len = p_pass - v9;
  v19 = &pass;
  v14 = v9;
  v19 += strlen(v19);
  v13 = ++v19 - v9;
  if ( (unsigned int)(v19 - v9) >= 0x126 )
  {
    if ( sub_3411D0(&pass) )
    {
      v18 = tmp_pass_len / 3;
      for ( i = 0; i < tmp_pass_len; ++i )
        key[i % v18] ^= v9[i - 1];
      for ( i = 0; i < flag_len; ++i )
        byte_344020[i] ^= key[i % v18];
      sub_341560("\n\nCongratulation! Here is your memo :> \n\n", v6);
      sub_341560("%s", (char)byte_344020);
    }
    else
    {
      sub_341560("\nInvalid password\n", v6);
    }
    getchar();
    getchar();
    return 0;
  }
  else
  {
    sub_341560("oh, no!", v6);
    return 0;
  }
}
````
- Hàm main nhập vào chuỗi `pass` và xử lí 2 điều kiện: độ dài password >= 294 kí tự và thỏa mãn hàm sub_3411D0
- Nếu 2 điều kiện trên được thỏa mãn, `pass` sẽ được lưu vào mảng key và được XOR để chuyển `byte_344020` thành flag

````
char __cdecl sub_3411D0(const char *a1)
{
  int i; // [esp+14h] [ebp-10h]
  int *v3; // [esp+18h] [ebp-Ch]

  v3 = (int *)&unk_344BE8;
  if ( (int)strlen(a1) < 55 )
    return 0;
  for ( i = 0; i < 122; ++i )
  {
    if ( !sub_341080(*v3, (int)&a1[v3[1]], (int)(v3 + 2)) )
      return 0;
    v3 += 3;
  }
  return 1;
}
````
- Tại hàm này, các kí tự sẽ được nhập ở dạng chuỗi byte, và hàm `sub_341080` sẽ xử lí 3 đối số lấy ra từ chuỗi byte

````
char __cdecl sub_341080(int a1, int a2, int a3)
{
  char v4[4]; // [esp+0h] [ebp-20h] BYREF
  LPVOID v5; // [esp+4h] [ebp-1Ch]
  LPVOID v6; // [esp+8h] [ebp-18h]
  SIZE_T v7; // [esp+Ch] [ebp-14h]
  SIZE_T v8; // [esp+10h] [ebp-10h]
  LPVOID lpAddress; // [esp+14h] [ebp-Ch]
  SIZE_T dwSize; // [esp+18h] [ebp-8h]
  char v11; // [esp+1Fh] [ebp-1h]

  v8 = 221;
  v5 = (LPVOID)resolve_func((int)&unk_344288, 0xDDu, 5);
  v7 = 278;
  v6 = (LPVOID)resolve_func((int)&unk_344170, 0x116u, 6);
  if ( !v5 || !v6 )
    return 0;
  switch ( a1 )
  {
    case 1:
      dwSize = 97;
      lpAddress = (LPVOID)resolve_func((int)&unk_344B80, 0x61u, 1);
      break;
    case 2:
      dwSize = 142;
      lpAddress = (LPVOID)resolve_func((int)&unk_344AF0, 0x8Eu, 2);
      break;
    case 3:
      dwSize = 1685;
      lpAddress = (LPVOID)resolve_func((int)&unk_344458, 0x695u, 3);
      break;
    case 4:
      dwSize = 235;
      lpAddress = (LPVOID)resolve_func((int)&unk_344368, 0xEBu, 4);
      break;
    default:
      return 0;
  }
  if ( !lpAddress )
    return 0;
  v11 = ((int (__cdecl *)(int, int, char *))lpAddress)(a2, a3, v4);
  VirtualFree(lpAddress, dwSize, 0x8000u);
  VirtualFree(v5, v8, 0x8000u);
  VirtualFree(v6, v7, 0x8000u);
  return v11;
}
````
- Hàm `sub_341080` chạy như sau:
  - Biến a1: nhận case được chọn để xử lí
  - Biến a2: là index trong chuỗi password
  - Biến a3: là biến chưa được xử lí
- Ta có thể dự đoán rằng code của 4 hàm trên đã bị shellcode mã hóa và hàm resolve_func sẽ giải mã và resolve các chương trình
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/5.png>

- Ta đặt breakpoint ở các dòng lệnh call, sau đó nhấn F9 2 lần để đến dòng `cmp [ebp+argv_0], 1` để bước vào case 1, F9 để vào case 1, F8 để nhảy tới lệnh sau đó, giá trị trả về của hàm resolve_func là địa chỉ được lưu tại eax
  
- Tiếp theo, chuột phải vào giá trị eax, jump tới địa chỉ đó, bấm phím C để make code và phím P để create function và cuối cùng nhấn F5 để tạo pseudocode
  
- Ta sẽ có hàm đầu tiên được resolve:
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/6.png>

  - Kiểm tra kí tự a[i] tại vị trí i bằng cách XOR với 0x20 nếu chẵn hoặc 0x52 nếu lẻ sau đó so sánh với BYTE trong data.

- Nếu như tiếp tục F9 thì chương trình sẽ kết thúc, vậy để chuyển sang case 2, ta sẽ debug lại, làm tới bước đến dòng `cmp [ebp+argv_0], 1` để bước vào case 1, qua stack view, chuột phải và chọn `Jump to EBP` để đến giá trị của EBP, bấm phím F2 và sửa thành `00000002` và bấm F2 thêm lần nữa để lưu
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/7.png>

- Vậy là ta đã có thể nhảy sang case 2, F9 cho đến khi vào được case 2. Tương tự với 3 hàm, ta sẽ được các hàm được resolve như sau:
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/8.png>

  - Kiểm tra kí tự a[i] và a[i+1] tại vị trí idx bằng cách dịch bit nhiều lần và XOR với 0x1693 sau đó so sánh với WORD trong data.
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/9.png>

  - Thuật toán mã hóa Base64 đã được sử dụng: `ABDCEHGFIJKLUNOPYRTSMVWXQZajcdefohibkmlngpqrstuv4xzy8123w56709+0` -> `ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/`
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/10.png>

  - Đây là thuật toán mã hóa RC4 với key là "susan" và bảng mã tại đầu hàm `sub_341080`
- Ta còn 2 hàm còn lại cũng bị shellcode nên ta sẽ làm tương tự như trên:
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/11.png>
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crack_me1/12.png>
## Code solve
