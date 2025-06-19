#include <stdio.h>

int count(int arr[], int len, int val) {
    int c = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == val) {
            c++;
        }
    }
    return c;
}

int main() {
    int n;
    int x;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Phan tu khong hop le\n");
        return 0;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");

    printf("Nhap mot so bat ky: ");
    scanf("%d", &x);

    int r = count(a, n, x);
    printf("%d", r);

    return 0;
}

