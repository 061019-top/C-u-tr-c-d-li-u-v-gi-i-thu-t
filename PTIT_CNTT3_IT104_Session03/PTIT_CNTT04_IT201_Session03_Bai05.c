#include <stdio.h>
#include <stdlib.h>

int sumMainDiag(int **a, int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i][i];
    return s;
}

int sumSecDiag(int **a, int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i][n - i - 1];
    return s;
}

int main() {
    int m, n;
    do {
        printf("Nhap so hang = ");
        scanf("%d", &m);
        if (m <= 0 || m >= 1000)
            printf("Khong hop le, thu lai\n");
    } while (m <= 0 || m >= 1000);

    do {
        printf("Nhap so cot = ");
        scanf("%d", &n);
        if (n <= 0 || n >= 1000)
            printf("Khong hop le, thu lai\n");
    } while (n <= 0 || n >= 1000);

    int **a = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        a[i] = malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    if (m == n) {
        int d1 = sumMainDiag(a, n);
        int d2 = sumSecDiag(a, n);
        printf("Tong duong cheo chinh = %d\n", d1);
        printf("Tong duong cheo phu = %d\n", d2);
    } else {
        printf("Khong ton tai duong cheo chinh\n");
        printf("Khong ton tai duong cheo phu\n");
    }

    for (int i = 0; i < m; i++)
        free(a[i]);
    free(a);

    return 0;
}
