#include <stdio.h>

int main() {
    int size;
    int index;

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
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");

    printf("Nhap vi tri muon xoa phan tu: ");
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Vi tri khong hop le\n");
        return 1;
    }

    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;

    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    return 0;
}

