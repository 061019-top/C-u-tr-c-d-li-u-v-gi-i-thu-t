#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *a;

    printf("Nhap so luong phan tu cua mang (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("Gia tri n khong hop le!\n");
        return 1;
    }

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    int s = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            s += a[i];
            c++;
        }
    }

    if (c == 0) {
        printf("Khong co so le nao trong mang!\n");
    } else {
        float tb = (float)s / c;
        printf("Trung binh cong cac so le la: %.2f\n", tb);
    }

    free(a);
    return 0;
}
