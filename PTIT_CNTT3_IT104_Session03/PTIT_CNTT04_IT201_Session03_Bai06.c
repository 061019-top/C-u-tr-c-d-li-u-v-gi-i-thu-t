#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("Khong hop le, thu lai\n");
        return 1;
    }

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Nhap so luong phan tu m: ");
    scanf("%d", &m);

    int t = n + m;
    int *b = malloc(t * sizeof(int));

    for (int i = 0; i < n; i++)
        b[i] = a[i];

    for (int i = n; i < t; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    free(a);

    for (int i = 0; i < t; i++)
        printf("%d ", b[i]);
    printf("\n");

    free(b);
    return 0;
}
