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
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    int index;
    int newValue;

    printf("Nhap vi tri muon sua: ");
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Vi tri khong hop le\n");
        return 1;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    array[index] = newValue;

    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    return 0;
}
