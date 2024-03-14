### [1] Lí thuyết
`Process`: là chương trình đang hoạt động trên CPU. 1 process có thể tạo ra các process con. Process gồm thanh ghi, ngăn xếp, dữ liệu, file và mã
  -  `Process Control Block (PCB)`: theo dõi trạng thái của process. Mỗi khối chứa thông tin về process ID (PID), trạng thái process, thanh ghi, thông tin quản lý bộ nhớ,...
  -  `Process Environment Block (PEB)`: liên kết với cấu trúc `EPROCESS`

`Thread`: là một phần của process. 1 process có thể có nhiều thread
  -   `Thread Control Block (TCB)`: bao gồm thread ID, trạng thái thread, thông tin CPU,..
  -   `Thread Environment Block (TEB)`: chứa thông tin của thread đang chạy và liên kết với cấu trúc `ETHREAD`

`Event`: là cơ chế để đồng bộ hóa và tương tác giữa các thread hoặc các process.

`Handle`: là cơ chế cho phép quản lý, truy cập và tài nguyên với các tài nguyên như: tệp tin, socket, thiết bị,...

`Session`: đại diện cho phiên làm việc giữa 2 hay nhiều thiết bị hoặc phiên đăng nhập của người dùng trong một khoảng thời gian (login session)

### [2] Thực hành
## [+] Exercise-1:

- Lập trình ứng dụng có chức năng tương tự lệnh `tasklist` của Windows. Hai cột thông tin bắt buộc là `Image Name` & `PID`.

- Mô tả:
  - Cấu trúc muốn liệt kê: Image Name, PID.

## [+] Exercise-2:

- Lập trình ứng dụng có chức năng tương tự lệnh `taskkill` của Windows. Hỗ trợ 2 phương thức terminate process (theo Image name hoặc theo ProcessID), chỉ định phương thức qua tham số truyền vào chương trình.

- Mô tả:
  - Sử dụng WindowsAPI -> `TerminateProcess(){}`.

## [+] Exercise-3:

- Viết chương trình mô phỏng cuộc thi chạy đua xử lý giữa 3 Thread:

  - Thread 1: đếm số từ trong file 1.txt.
  - Thread 2: đếm số file có trong thư mục hiện tại.
  - Thread 3: đếm số thread của process `explorer.exe`.

- Hiển thị ra màn hình thứ tự giải của 3 thread theo thời gian hoàn thành. Ví dụ:

```powershell
Thread 2: Giải nhất
Thread 1: Giải nhì
Thread 3: Giải ba
```

- Mô tả:
  - C1: Sử dụng WindowsAPI -> `GetThreadTimes(){}`.
  - C2: GetExitCodeThread(), getTicketCount(). 
