### [1] Lí thuyết
- Các dll chuẩn của hệ thống;
    - `Kernel32.dll` chứa các hàm giúp quản lý tài nguyên hệ thống, quản lý bộ nhớ, và cung cấp các chức năng hệ thống cơ bản. Một số chức năng:
        - Quản lý bộ nhớ: Kernel32.dll cung cấp các hàm như VirtualAlloc, VirtualFree, VirtualProtect,... để quản lý việc phân bổ và giải phóng bộ nhớ.
        - Quản lý tài nguyên: Kernel32.dll cung cấp các hàm như CreateFile, ReadFile, WriteFile, CloseHandle,... để làm việc với tệp tin, định vị và truy cập vào các tài nguyên hệ thống.
        - Process và thread: Kernel32.dll cung cấp các hàm như CreateProcess, TerminateProcess, CreateThread, Sleep,... để quản lý các tiến trình và luồng trong hệ thống.
        - Sử dụng thời gian và ngày: Kernel32.dll cung cấp các hàm như GetSystemTime, GetLocalTime, GetTickCount,... để lấy thông tin về thời gian và ngày tháng từ hệ thống.
        - Giao tiếp với hệ thống tệp tin: Kernel32.dll cung cấp các hàm như FindFirstFile, FindNextFile, GetFileAttributes,... để tìm kiếm và tương tác với các tệp tin và thư mục trong hệ thống tệp tin.
    - `Advapi32.dll` cung cấp các hàm và giao diện lập trình ứng dụng (API) liên quan đến bảo mật, quản lý tài khoản, và quản lý service trong hệ thống. Một số chức năng:
        - Bảo mật: Advapi32.dll cung cấp các hàm như LogonUser, ImpersonateLoggedOnUser, EncryptFile, DecryptFile,... để xác thực người dùng, ủy quyền, mã hóa và giải mã tệp tin.
        - Quản lý tài khoản: Advapi32.dll cung cấp các hàm như CreateAccount, DeleteAccount, ChangePassword,... để quản lý tài khoản người dùng, nhóm người dùng, và đặc quyền truy cập.
        - Quản lý service: Advapi32.dll cung cấp các hàm như OpenService, StartService, ControlService, QueryServiceStatus,... để tạo, quản lý và tương tác với các service trong hệ thống.
        - Event và Log: Advapi32.dll cung cấp các hàm như RegisterEventSource, ReportEvent, OpenEventLog, ReadEventLog,... để ghi và quản lý các event và system log.
        - Mã hóa và giải mã: Advapi32.dll cung cấp các hàm như CryptEncrypt, CryptDecrypt, CryptHashData,... để thực hiện các hoạt động mã hóa và giải mã dữ liệu.
    - `Gdi32.dll` chứa các hàm và API liên quan đến đồ họa và xử lý hình ảnh trong hệ thống. Một số chức năng:
        - Quản lý các thiết bị hiển thị: Gdi32.dll cung cấp các hàm như CreateDC, CreateCompatibleDC, DeleteDC,... để tạo, quản lý và tương tác với các thiết bị hiển thị (display devices) trong hệ thống.
        - Quản lý font chữ: Gdi32.dll cung cấp các hàm như CreateFont, DeleteFont, GetTextMetrics,... để tạo, quản lý và tương tác với các font chữ trong hệ thống.
        - Xử lý hình ảnh: Gdi32.dll cung cấp các hàm như CreateBitmap, CreateDIBSection, StretchBlt,... để tạo, xử lý và tương tác với các hình ảnh và bitmap.
        - Vẽ vùng đồ họa: Gdi32.dll cung cấp các hàm như CreateRectRgn, CombineRgn, FillRgn,... để tạo, kết hợp và điền màu vào các vùng đồ họa trong hệ thống.
    - `Shell32.dll` chứa các hàm và API liên quan đến giao diện người dùng, quản lý tệp tin, và tích hợp hệ thống trong Windows. Một số chức năng:
        - Giao diện người dùng: Shell32.dll cung cấp các hàm và chức năng để tạo, quản lý và tương tác với các yếu tố giao diện người dùng trong Windows, bao gồm các cửa sổ, thanh công cụ, menu và các yếu tố khác như biểu tượng và hình ảnh.
        - Quản lý tệp tin và thư mục: Shell32.dll cung cấp các hàm như SHGetFolderPath, SHGetFileInfo, SHFileOperation,... để truy xuất thông tin về tệp tin và thư mục, thao tác với tệp tin và thư mục, và tạo các hộp thoại quản lý tệp tin.
        - Tích hợp hệ thống: Shell32.dll cung cấp các hàm như ShellExecute, Shell_NotifyIcon, SHAppBarMessage,... để tích hợp với các thành phần hệ thống khác và thực hiện các hoạt động như thực thi tệp tin, hiển thị biểu tượng hệ thống, và tương tác với thanh tác vụ (taskbar).
        - Hỗ trợ COM (Component Object Model): Shell32.dll cung cấp các hàm và giao diện COM để tương tác với các đối tượng COM liên quan đến giao diện người dùng và quản lý tệp tin trong hệ thống.
    - User32.dll là chứa các hàm và API liên quan đến giao diện người dùng, nhập liệu từ bàn phím và chuột, và quản lý cửa sổ trong hệ thống. Một số chức năng:
        - Giao diện người dùng: User32.dll cung cấp các hàm và chức năng để tạo, quản lý và tương tác với các yếu tố giao diện người dùng trong Windows, bao gồm cửa sổ, thanh công cụ, menu, hộp thoại và các yếu tố khác như nút bấm, hộp văn bản, và hình ảnh.
        - Xử lý event: User32.dll cung cấp các hàm như DispatchMessage, TranslateMessage, GetMessage,... để xử lý và chuyển tiếp các event từ bàn phím, chuột và các yếu tố giao diện khác đến các cửa sổ và ứng dụng.
        - Quản lý cửa sổ: User32.dll cung cấp các hàm như CreateWindowEx, DestroyWindow, SetWindowPos,... để tạo, quản lý và tương tác với các cửa sổ trong hệ thống, bao gồm desktop và cửa sổ ứng dụng.
        - Nhận thông tin đâu vào từ bàn phím và chuột: User32.dll cung cấp các hàm như GetKeyboardState, GetCursorPos, SetCursorPos,... để nhận thông tin về event từ bàn phím và chuột, và thực hiện các hoạt động liên quan đến đầu vào người dùng.
        - Hiển thị và điều khiển: User32.dll cung cấp các hàm như ShowWindow, UpdateWindow, EnableWindow,... để hiển thị và điều khiển các cửa sổ, cập nhật nội dung và trạng thái của các yếu tố giao diện.
    - Comctl32.dll chứa các hàm và API liên quan đến các điều khiển giao diện người dùng và tính năng trình điều khiển của Windows. Một số chức năng:
        - Điều khiển giao diện người dùng thông thường: Comctl32.dll cung cấp các hàm và chức năng để tạo, quản lý và tương tác với các điều khiển giao diện người dùng thông thường như nút bấm, hộp văn bản, danh sách, cây thư mục, thanh cuộn và thanh tiến trình. 
        - Thay đổi giao diện người dùng: Comctl32.dll cung cấp các hàm và chức năng để thay đổi giao diện người dùng trong Windows, bao gồm tạo các thanh công cụ, thanh trạng thái, thanh tiêu đề, menu và các phần khác của giao diện người dùng.
        - Quản lý hộp thoại: Comctl32.dll cung cấp các hàm như PropertySheet, MessageBoxIndirect, TaskDialog,... để tạo và quản lý các hộp thoại trong Windows, bao gồm hộp thoại thông báo, hộp thoại cấu hình và các hộp thoại khác.
        - Tích hợp hệ thống: Comctl32.dll cung cấp các hàm và chức năng để tích hợp với các thành phần hệ thống khác trong Windows, bao gồm tích hợp với thanh tác vụ (taskbar), menu ngữ cảnh, hộp thoại tìm kiếm và các tính năng khác của hệ điều hành.
    - Comdlg32.dll chứa các hàm và API liên quan đến các hộp thoại quản lý tệp tin và hộp thoại giao tiếp với người dùng trong Windows. Một số chức năng:
        - Hộp thoại mở và lưu tệp tin: Comdlg32.dll cung cấp các hàm như GetOpenFileName, GetSaveFileName,... để hiển thị hộp thoại mở và lưu tệp tin. Đây là các hộp thoại tiêu chuẩn được sử dụng để cho phép người dùng chọn tệp tin từ hệ thống tệp tin và chỉ định vị trí lưu tệp tin.
        - Hộp thoại in: Comdlg32.dll cung cấp các hàm như PrintDlg, PageSetupDlg,... để hiển thị hộp thoại in và cấu hình các tùy chọn in. Các hộp thoại này cho phép người dùng chọn máy in, cấu hình bố cục in, chọn trang in và các tùy chọn in khác.
        - Hộp thoại thông báo: Comdlg32.dll cung cấp các hàm như MessageBox, MessageBoxEx,... để hiển thị các hộp thoại thông báo cho người dùng. Đây là các hộp thoại được sử dụng để hiển thị thông tin, cảnh báo hoặc yêu cầu xác nhận từ người dùng.
        - Hộp thoại màu sắc: Comdlg32.dll cung cấp các hàm như ChooseColor, ChooseFont,... để hiển thị hộp thoại chọn màu sắc và chọn font. Các hộp thoại này cho phép người dùng chọn màu sắc và font chữ từ các tùy chọn có sẵn.
- Build & load dll:
    - Build: 
        - Tạo file header: dùng __declspec(dllexport) và __declspec(dllimport) để export 1 function
        - Tạo file C++ để DLL nhận dạng được function để export
    - Load:
        - Sử dụng hàm LoadLibrary để load DLL
        - Sử dụng hàm FreeLibrary để giải phóng DLL
- Export function:
    - Sử dụng __declspec(dllexport) để định nghĩa function muốn export và sử dụng __declspec(dllimport) để import DLL function đã được export
### [2] Thực hành
## [+] Exercise-1:

- Lập trình chương trình có chức năng giống `rundll32.exe` của hệ thống:

```cmd
RUNDLL32.EXE <dllname>,<entrypoint> <optional arguments>
```

## [+] Exercise-2:

- Lập trình 1 dll có chức năng khi được nạp lên hiển thị thông điệp: `"Hi! Im a DLL"`.

## [+] Exercise-3:

- Lập trình 1 dll export 2 function.
  - Function 1 nhận tham số đầu vào là 1 chuỗi ký tự, khi được gọi hiển thị thông điệp là chuỗi ký tự đã truyền vào.
  - Function 2 nhận tham số đầu vào là tên file, khi được gọi ghi nội dung bất kỳ vào file đó.
