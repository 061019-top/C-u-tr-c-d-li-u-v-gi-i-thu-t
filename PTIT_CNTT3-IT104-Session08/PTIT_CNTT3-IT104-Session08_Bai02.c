//
// Created by ADMIN on 7/1/2025.
//
#include <stdio.h>

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Hàm sắp xếp nổi bọt
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("Khong hop le\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Mang sau sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int x;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    int index = binarySearch(arr, 0, n - 1, x);
    if (index != -1) {
        printf("Phan tu o vi tri thu %d (chi so %d)\n", index + 1, index);
    } else {
        printf("Khong ton tai phan tu\n");
    }

    return 0;
}
