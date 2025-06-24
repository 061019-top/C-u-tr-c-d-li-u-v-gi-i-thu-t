#include <stdio.h>

int main() {
    int size;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("So phan tu khong hop le!");
        return 1;
    }

    int numbers[size];
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    printf("Phan tu lon nhat trong mang la: %d\n", max);
    return 0;
}
