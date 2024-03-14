### [1] Lí thuyết
`Virtual Address Space`: là tập hợp các dải địa chỉ ảo mà hệ điều hành cung cấp cho một process. Mỗi process có một không gian địa chỉ ảo riêng. Trong không gian địa chỉ ảo có những bộ phận quan trọng sau:
  - `Page`: Là một block bộ nhớ có độ lớn không đổi, được dùng để quản lí bộ nhớ ảo.
  - `Code Segment`: Là một phần của địa chỉ ảo chứa các lệnh thực thi của process.
  - `Data Segment`: Là một phần của địa chỉ ảo chứa bộ nhớ cấp và biến của process.
  - `Page Table`: Là cấu trúc dữ liệu mà hệ điều hành theo dõi sự trao đổi giữa page ảo và khung bộ nhớ thực.

`Address Translating`: Quản lý bộ nhớ dịch địa chỉ logic (sử dụng trong process) sang địa chỉ vật lý (sử dụng trong phần cứng), giúp ứng dụng có thể truy cập và lưu trữ dữ liệu trong bộ nhớ mà không cần biết địa chỉ vật lý thực tế.
  - `Địa chỉ logic (logical address)`: được tạo ra bởi CPU trong khi một chương trình đang hoạt động. Địa chỉ logic hay còn được gọi là địa chỉ ảo.
  - `Địa chỉ vật lý (physical address)`: nhận diện địa chỉ vật lí của dữ liệu trong một bộ nhớ. Địa chỉ vật lý hay còn được gọi là địa chỉ thực.

`Protection Attribute`: chỉ các thuộc tính hoặc đặc điểm của một tài nguyên hoặc hệ thống, được thiết lập để bảo vệ và đảm bảo tính bảo mật của chúng. Các thuộc tính bảo vệ bao gồm: PAGE - EXECUTE - READ - WRITE

### [2] Thực hành
## [+] Exercise-1:

- Lập trình ứng dụng có chức năng tương tự lệnh `systeminfo` của Windows.

  - Sử dụng WindowsAPI nhằm query thông tin của Registry như: `RegOpenKeyExW`, `RegQueryValueExW`, ...


## [+] Exercise-2:

- Lập trình ứng dụng có chức năng liệt kê các vùng nhớ có Protection Attribute là PAGE_EXECUTE_READ_WRITE trong Process Memory Space của tiến trình chỉ định qua tham số (truyền vào ProcessID).

  - Sử dụng WindowsAPI nhằm query thông tin của process như: `OpenProcess`, `VirtualQueryEx`...
