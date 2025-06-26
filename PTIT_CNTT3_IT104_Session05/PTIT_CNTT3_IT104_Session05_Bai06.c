#include <stdio.h>
#include <stdlib.h>

// Hàm đệ quy tính tổng các phần tử mảng
int sumArr(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n - 1] + sumArr(arr, n - 1);
}

int main() {
    int n;
    // B1: Nhập số phần tử
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    // B2: Cấp phát động bộ nhớ cho mảng
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return -1;
    }

    // B3: Nhập các phần tử của mảng
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // B4: Gọi hàm tính tổng và in kết quả
    int res = sumArr(arr, n);
    printf("Tong cac phan tu trong mang la: %d\n", res);

    // B5: Giải phóng bộ nhớ
    free(arr);
    return 0;
}

