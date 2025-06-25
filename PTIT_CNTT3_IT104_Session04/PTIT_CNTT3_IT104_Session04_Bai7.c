#include <stdio.h>

int main() {
    // B1: Khai báo biến 'size' để lưu số lượng phần tử của mảng
    int size;
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

    int foundSymmetricPair = 0;
    // B5: Khai báo biến để kiểm tra có tồn tại cặp đối xứng hay không

    for (int i = 0; i < size / 2; i++) {
        // B6: So sánh phần tử ở đầu với phần tử đối xứng phía cuối
        if (array[i] == array[size - i - 1]) {
            printf("Cap doi xung: (%d, %d)\n", array[i], array[size - i - 1]);
            foundSymmetricPair = 1; // Có ít nhất một cặp đối xứng
        }
    }

    // B7: Nếu không có cặp đối xứng nào thì in thông báo
    if (foundSymmetricPair == 0) {
        printf("Khong co phan tu doi xung\n");
    }

    return 0;
}

