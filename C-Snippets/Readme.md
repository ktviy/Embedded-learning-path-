# C-Snippets: Fundamental C Programming for Low-Level Systems

## Giới thiệu
Repository này chứa các đoạn mã C (snippets) tập trung vào các khái niệm nền tảng, đặc biệt là **Con trỏ (Pointers)** và **Quản lý Bộ nhớ Động (Dynamic Memory Allocation)**. Những kỹ năng này là cốt lõi cho việc phát triển **Embedded Systems** và **High-Performance Computing (HPC)**, nơi kiểm soát bộ nhớ thủ công là điều kiện tiên quyết.

## Giá trị Kỹ thuật
Các ví dụ trong đây chứng minh khả năng:
1.  **Quản lý Bộ nhớ Thủ công:** Sử dụng `malloc()`, `calloc()`, `realloc()`, và `free()` để cấp phát và giải phóng bộ nhớ trên Heap.
2.  **Lập trình Cấp thấp (Low-Level):** Hiểu cách các biến được lưu trữ trong bộ nhớ và cách Con trỏ được dùng để thao tác trực tiếp với địa chỉ (cần thiết cho Embedded I/O và tối ưu hóa HPC).
3.  **Tư duy Lập trình Hệ thống:** Tránh các lỗi rò rỉ bộ nhớ (Memory Leaks) và lỗi truy cập ngoài phạm vi (Out-of-bounds access).

## Cấu trúc Thư mục

| Thư mục | Trọng tâm | Liên kết với Dự án |
| :--- | :--- | :--- |
| `01_Basic_Pointers` | Toán tử con trỏ, tham chiếu và giải tham chiếu.
| `02_Dynamic_Memory` | `malloc`, `realloc`, `free` cho các cấu trúc dữ liệu linh hoạt. | Cấp phát các vùng bộ nhớ lớn - Ma trận |
| `03_Function_Pointers`| Con trỏ hàm, mô phỏng cơ chế Callbacks/Interrupts. | **P1 (Embedded/RTOS):** Lập trình Event-Driven. |
