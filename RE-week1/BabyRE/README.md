## Phân tích
Ta nhận được 1 file PE32:

<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/BabyRE/1.png>

Mình dùng IDA để xem và sửa một chút ở pseudocode:

````
int __cdecl main(int argc, const char **argv, const char **envp)
{
  unsigned int i; // esi
  int j; // edi
  char *flag; // esi
  int v6; // ecx
  char key[26]; // [esp+0h] [ebp-28h] BYREF
  char v9[8]; // [esp+1Ch] [ebp-Ch] BYREF

  qmemcpy(key, "bdnpQai|nufimnug`n{Fafhr", 24);
  *(_WORD *)&key[24] = 1111;
  sub_401020("Guest your flag. The flag will be of the form flag{[a-zA-Z0-9]+}\n");
  sub_401020("Enter your key:");
  for ( i = 0; i < 5; ++i )
    sub_401050("%hhd", &v9[i]);
  for ( j = 0; j < 26; j += 2 )
  {
    flag = &key[j];
    *flag ^= v9[j % 5u];
    v6 = j;
    flag[1] ^= v9[v6 - 5 * ((unsigned int)&flag[1 - (_DWORD)key] / 5) + 1];
  }
  sub_401020("flag is : %s\n");
  return 0;
}
````

- Đọc đoạn code trên ta có thể thấy chương trình sẽ nhận 5 số làm input, sau đó 5 số đó sẽ được XOR với key = "bdnpQai|nufimnug`n{Fafhr"

## Code solve
Ta sẽ tìm flag dựa trên form flag là: flag{ và 5 kí tự đầu của key:

````
key = "bdnpQ"
flag = "flag{"
for i in range(5):
  print(ord(flag[i]) ^ ord(key[i]))
````

Chạy code trên và ta nhận được 5 số là: 4 8 15 23 42
Nhập 5 số và ta nhận được flag: `flag{easy_baby_challenge}`
