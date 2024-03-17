## Phân tích
Ta nhận được 1 file exe và 1 bức ảnh. Dùng lệnh file để biết đây là 1 file PE32:
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crackme_1/2.png>

Mở IDA và xem pseudocode. Ta sẽ phân tích từng phần như sau:
````
FileW = CreateFileW((LPCWSTR)argv[1], 0xC0000000, 1u, 0, 3u, 0x80u, 0);
      v5 = FileW;
      v23 = FileW;
      if ( FileW != (HANDLE)-1 )
      {
        FileSize = GetFileSize(FileW, 0);
        if ( FileSize == -1
          || (FileMappingW = CreateFileMappingW(v5, 0, 4u, 0, 0, 0), v8 = FileMappingW, (hObject = FileMappingW) == 0) )
        {
          CloseHandle(v5);
          return 0;
        }
        lpBaseAddress = (char *)MapViewOfFile(FileMappingW, 6u, 0, 0, 0);
````
Đầu tiên chương trình sẽ nhận 3 đối số truyền vào. CreateFileW sẽ mở file ảnh ra, CreateFileMappingW sẽ tạo file mapping của file ảnh và MapViewOfFile sẽ map vào memory process.

````
            v12 = Dest[v10];
            v9[bit] = v12 & 1;
            v9[bit + 1] = (v12 >> 1) & 1;
            v9[bit + 2] = (v12 >> 2) & 1;
            v9[bit + 3] = (v12 >> 3) & 1;
            v9[bit + 4] = (v12 >> 4) & 1;
            v9[bit + 5] = (v12 >> 5) & 1;
            v9[bit + 6] = (v12 >> 6) & 1;
            v10 = v32 + 1;
            v9[bit + 7] = (v12 >> 7) & 1;
            bit += 8;
            v32 = v10;
````
Trong đoạn code này, từng bit của string sẽ được mã hóa, ví dụ: v9[bit] = v12 & 1 đặt bit thấp nhất của v12 vào v9[bit]

``
if ( *(_WORD *)lpBaseAddress == 0x4D42 && FileSize >= *(_DWORD *)(lpBaseAddress + 2) )
``
Dòng này sẽ kiểm tra xem có map vào file signature của file ảnh không (do 0x4D42 chuyển sang ASCII là BM)
<img src= https://github.com/dxisdh/RE/blob/main/RE-week1/crackme_1/3.png>

````
              start_data = v17;
              *((_WORD *)lpBaseAddress + 3) = bit;
              v33 = 0;
              if ( bit )
              {
                v19 = 0;
                v31 = 0;
                do
                {
                  if ( v18 >= height )
                    break;
                  v20 = 0;
                  if ( cnt < bit )
                  {
                    do
                    {
                      if ( v20 >= width )
                        break;
                      v21 = v19 + v20++;
                      bit_value = bit_map[cnt++];
                      start_data[2 * v21 + v21] = bit_value;
                      v19 = v31;
                      width = v25;
                    }
                    while ( cnt < bit );
                    v18 = v33;
                  }
                  ++v18;
                  v19 += 3 * width;
                  v33 = v18;
                  v31 = v19;
````
Mảng start_data sẽ lưu chuỗi bit đã được mã hóa để giấu flag trong ảnh, trong đó v21 là các dải bit được chiếu lên map process

## Code solve
````
data = list(open("E://Code//RE//vcs//RE//inside-the-mind-of-a-hacker-memory.bmp", "rb").read())
width = 0x3AA
height = 0x244
cntH = 0
i = 0
flag = len(data) * [0]
while(i < len(data)):
    v19 = 0
    if(cntH >= height):
        break
    cntW = 0
    while i < len(data):
        if(cntW >= width):
            break
        v21 = v19 + cntW
        flag[i] = data[0x36 + 3 * v21] // 0x36 là phần đằng sau file signature
        v19 += 1
        i += 1
    cntH += 1
    v19 += 3 * width
for i in range(0, 790, 8):
    f = flag[i + 7] << 7 + flag[i + 6] << 6 + flag[i + 5] << 5 + flag[i + 4] << 4 + flag[i + 3] << 3 + flag[i + 2] << 2 + flag[i + 1] << 1 + flag[i]
    print(chr(f))
````
Chạy chương trình trên ta sẽ nhận được flag: `flag{dont_forget_the_treasure}`
