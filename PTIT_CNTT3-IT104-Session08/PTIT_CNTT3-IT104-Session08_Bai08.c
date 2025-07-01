//
// Created by ADMIN on 7/1/2025.
//
#include <stdio.h>

// Hàm sắp xếp chèn (Insertion Sort)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Tìm kiếm tuyến tính
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Tìm kiếm nhị phân
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le.\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int x;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &x);

    int searchByLinear = linearSearch(arr, n, x);
    int searchByBinary = binarySearch(arr, 0, n - 1, x);

    if (searchByLinear != -1) {
        printf("Tuyen tinh: Phan tu o vi tri thu %d.\n", searchByLinear + 1);
    } else {
        printf("Tuyen tinh: Khong tim thay phan tu.\n");
    }

    if (searchByBinary != -1) {
        printf("Nhi phan: Phan tu o vi tri thu %d.\n", searchByBinary + 1);
    } else {
        printf("Nhi phan: Khong tim thay phan tu.\n");
    }

    return 0;
}
