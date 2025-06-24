#include <stdio.h>
#include <stdlib.h>

#define MIN_VAL -10000
#define MAX_VAL 10000

int main() {
    int m, n;

    do {
        printf("Nhap so hang = ");
        scanf("%d", &m);
        if (m < 0 || m > 100)
            printf("Khong hop le, thu lai\n");
    } while (m < 0 || m > 100);

    do {
        printf("Nhap so cot = ");
        scanf("%d", &n);
        if (n < 0 || n > 100)
            printf("Khong hop le, thu lai\n");
    } while (n < 0 || n > 100);

    int **a = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        a[i] = malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    int max = MIN_VAL, min = MAX_VAL;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j] > max) max = a[i][j];
            if (a[i][j] < min) min = a[i][j];
        }

    printf("Max = %d, Min = %d\n", max, min);

    for (int i = 0; i < m; i++)
        free(a[i]);
    free(a);

    return 0;
}
