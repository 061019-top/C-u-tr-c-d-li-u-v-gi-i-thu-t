//
// Created by ADMIN on 6/30/2025.
//
#include <stdio.h>

// Hàm chia mảng và trả về chỉ số pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // chọn phần tử cuối làm pivot
    int i = low - 1; // chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // hoán đổi arr[i] và arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // đưa pivot về đúng vị trí
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Hàm sắp xếp quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);  // sắp bên trái
        quicksort(arr, pivotIndex + 1, high); // sắp bên phải
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
