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
