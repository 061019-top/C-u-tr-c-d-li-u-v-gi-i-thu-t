#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;

    do {
        printf("Nhap so luong phan tu (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int pos;
    printf("Nhap vi tri muon xoa (0 den %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le.\n");
        free(arr);
        return 1;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Mang sau khi xoa:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
