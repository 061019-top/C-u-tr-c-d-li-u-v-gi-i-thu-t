#include <stdio.h>
#include <stdlib.h>

int sumRow(int **a, int n, int k) {
    int s = 0;
    for (int j = 0; j < n; j++)
        s += a[k][j];
    return s;
}

int main() {
    int m, n;
    do {
        printf("Nhap so hang: ");
        scanf("%d", &m);
        if (m <= 0 || m >= 1000)
            printf("Khong hop le\n");
    } while (m <= 0 || m >= 1000);

    do {
        printf("Nhap so cot: ");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000)
            printf("Khong hop le\n");
    } while (n <= 0 || n >= 1000);

    int **a = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        a[i] = malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }

    int k;
    printf("Nhap dong k: ");
    scanf("%d", &k);

    if (k < 0 || k >= m)
        printf("Dong khong ton tai\n");
    else {
        int s = sumRow(a, n, k);
        printf("Tong = %d\n", s);
    }

    for (int i = 0; i < m; i++)
        free(a[i]);
    free(a);

    return 0;
}
