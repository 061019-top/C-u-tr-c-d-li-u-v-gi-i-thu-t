#include <stdio.h>

int main() {
    int size;
    // Bước 1: Khai báo biến 'size' để lưu số phần tử của mảng
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);

    int array[size];
    // Bước 2: Khai báo mảng 'array' có 'size' phần tử

    for (int i = 0; i < size; i++) {
        // Bước 3: Sử dụng vòng lặp để nhập giá trị cho từng phần tử trong mảng
        printf("phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++) {
        // Bước 4: Sử dụng vòng lặp để in tất cả các phần tử của mảng
        printf("%d ", array[i]);
    }
    printf("\n");

    int target;
    // Bước 5: Khai báo biến 'target' để lưu giá trị cần tìm
    printf("Nhap mot gia tri bat ky: ");
    scanf("%d", &target);

    int foundIndex = -1;
    // Bước 6: Khởi tạo biến 'foundIndex' để lưu chỉ số tìm được (nếu không tìm thấy thì giữ -1)

    for (int i = 0; i < size; i++) {
        // Bước 7: Duyệt qua mảng để tìm phần tử có giá trị bằng 'target'
        if (array[i] == target) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // Bước 8: Kiểm tra kết quả và in ra chỉ số nếu tìm thấy
        printf("%d\n", foundIndex);
    } else {
        printf("Khong tim thay phan tu");
    }

    return 0;
}
