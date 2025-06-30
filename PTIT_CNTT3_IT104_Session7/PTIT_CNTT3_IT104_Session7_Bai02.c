//
// Created by ADMIN on 6/30/2025.
//
#include <stdio.h>

// Hàm sắp xếp chọn (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // giả sử phần tử tại i là nhỏ nhất
        for (int j = i + 1; j < n; j++) {
            // tìm phần tử nhỏ hơn phần tử tại minIndex
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // cập nhật vị trí phần tử nhỏ nhất
            }
        }
        // hoán đổi nếu cần thiết
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
    // Nhập các phần tử của mảng
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
    selectionSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("After: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
