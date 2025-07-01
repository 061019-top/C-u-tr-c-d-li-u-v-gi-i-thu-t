//
// Created by ADMIN on 7/1/2025.
//
#include <stdio.h>

// Hàm phân hoạch
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // phần tử chốt
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Đưa pivot về đúng vị trí
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Hàm Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Hàm in mảng
void printArray(int arr[], int n, const char *label) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printArray(arr, n, "Mang truoc khi sap xep");

    quickSort(arr, 0, n - 1);

    printArray(arr, n, "Mang sau khi sap xep");

    return 0;
}
