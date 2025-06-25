#include <stdio.h>

int main() {
    int size;
    // B1: Khai báo biến 'size' để lưu số phần tử của mảng
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);

    int array[size];
    // B2: Khai báo mảng 'array' có 'size' phần tử
    for (int i = 0; i < size; i++) {
        // B3: Sử dụng vòng lặp để nhập giá trị các phần tử
        printf("phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++) {
        // B4: Sử dụng vòng lặp để in ra giá trị các phần tử
        printf("%d ", array[i]);
    }
    printf("\n");

    int target;
    // B5: Khai báo biến 'target' để lưu giá trị cần tìm
    printf("Nhap gia tri bat ky: ");
    scanf("%d", &target);

    int foundIndex = -1;
    // B6: Khai báo biến 'foundIndex' để lưu chỉ số tìm được, gán -1 nếu không tìm thấy

    for (int i = size - 1; i >= 0; i--) {
        // B7: Duyệt mảng từ cuối về đầu để tìm phần tử cuối cùng có giá trị bằng 'target'
        if (array[i] == target) {
            foundIndex = i;
            break;
        }
    }

    // B8: In ra kết quả
    if (foundIndex != -1) {
        printf("%d\n", foundIndex);
    } else {
        printf("Khong tim thay phan tu");
    }

    return 0;
}

