#include <stdio.h>

int main() {
    int size;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Phan tu khong hop le\n");
        return 1;
    }

    int array[size];
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }

    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    return 0;
}

