//
// Created by ADMIN on 6/30/2025.
//
#include <stdio.h>

// Hàm sắp xếp chèn (Insertion Sort)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // bắt đầu từ phần tử thứ 2
        int key = arr[i]; // phần tử cần chèn
        int j = i - 1;

        // Dời các phần tử lớn hơn key sang bên phải
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Chèn key vào đúng vị trí
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Khong hop le\n");
        return 1;
    }

    int arr[n];
    // Nhập mảng
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In mảng trước khi sắp xếp
    printf("Before: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Gọi hàm sắp xếp
    insertionSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("After: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
