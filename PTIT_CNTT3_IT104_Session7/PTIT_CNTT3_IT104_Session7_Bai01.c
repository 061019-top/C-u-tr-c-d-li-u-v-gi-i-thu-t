//
// Created by ADMIN on 6/30/2025.
//
#include <stdio.h>

// Hàm sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Lặp qua từng cặp phần tử liền kề
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Đổi chỗ nếu sai thứ tự
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    // Kiểm tra điều kiện hợp lệ
    if (n <= 0 || n > 100) {
        printf("Khong hop le\n");
        return 1;
    }

    int arr[n];

    // Nhập từng phần tử vào mảng
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In mảng ban đầu
    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Gọi hàm sắp xếp
    bubbleSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("Mang sau sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
