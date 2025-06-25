#include <stdio.h>

int main() {
    int size;
    // B1: Khai báo biến 'size' để lưu số lượng phần tử của mảng
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &size);

    int array[size];
    // B2: Khai báo mảng 'array' có 'size' phần tử

    for (int i = 0; i < size; i++) {
        // B3: Sử dụng vòng lặp để nhập giá trị cho từng phần tử
        printf("phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++) {
        // B4: In ra toàn bộ mảng
        printf("%d ", array[i]);
    }
    printf("\n");

    int target;
    // B5: Khai báo biến 'target' để lưu giá trị cần tìm
    printf("Nhap gia tri bat ky: ");
    scanf("%d", &target);

    int found = 0;
    // B6: Biến 'found' dùng để kiểm tra xem có tìm thấy hay không

    for (int i = 0; i < size; i++) {
        // B7: Duyệt qua từng phần tử của mảng
        if (array[i] == target) {
            printf("%d, ", i);
            found = 1; // Đánh dấu đã tìm thấy
        }
    }

    // B8: Nếu không tìm thấy thì in thông báo
    if (found == 0) {
        printf("Phan tu khong co trong mang");
    }

    return 0;
}

