#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;

    do {
        printf("Nhap so luong phan tu (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    arr = (int*)malloc((n + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int pos, value;
    printf("Nhap vi tri muon them (0 den %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Vi tri khong hop le.\n");
        free(arr);
        return 1;
    }

    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;

    printf("Mang sau khi them phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}