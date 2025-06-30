//
// Created by ADMIN on 6/30/2025.
//
#include <stdio.h>

// Gộp 2 mảng con lại với nhau
void merge(int arr[], int left, int mid, int right) {
    int nLeft = mid - left + 1;
    int nRight = right - mid;

    int L[nLeft], R[nRight];

    // Sao chép dữ liệu
    for (int i = 0; i < nLeft; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < nRight; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < nLeft && j < nRight) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < nLeft) {
        arr[k++] = L[i++];
    }
    while (j < nRight) {
        arr[k++] = R[j++];
    }
}

// Hàm sắp xếp đệ quy
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);      // Sắp xếp nửa trái
        mergeSort(arr, mid + 1, right); // Sắp xếp nửa phải
        merge(arr, left, mid, right);   // Gộp lại
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le");
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

    mergeSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

