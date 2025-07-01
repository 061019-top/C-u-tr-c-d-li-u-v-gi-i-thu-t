//
// Created by ADMIN on 7/1/2025.
//
#include <stdio.h>

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

    printf("Mang vua nhap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int search;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &search);

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            index = i;
            break;
        }
    }

    printf("search = %d\n", search);
    if (index != -1) {
        printf("Vi tri trong mang (bat dau tu 1): %d\n", index + 1);
    } else {
        printf("Khong ton tai phan tu trong mang\n");
    }

    return 0;
}
