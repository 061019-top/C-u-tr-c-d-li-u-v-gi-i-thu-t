#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
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
        printf("arr[%d] = ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so can kiem tra: ");
    scanf("%d", &x);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }

    printf("So %d xuat hien %d lan trong mang.\n", x, count);

    free(arr);
    return 0;
}
