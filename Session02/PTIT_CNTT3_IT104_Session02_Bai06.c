#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100)
    {
        printf("So luong phan tu khong hop le");
        return 1;
    }

    int *array = (int *) malloc(size * sizeof(int));
    if (array == NULL)
    {
        printf("Bo nho khong the cap phat!");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int index;
    int value;
    printf("Nhap vi tri ma ban muon chen vao mang tren: ");
    scanf("%d", &index);
    printf("Nhap gia tri ma ban muon chen vao mang tren: ");
    scanf("%d", &value);

    if (index < 0 || index > size)
    {
        printf("Vi tri nhap vao khong hop le!");
        free(array);
        return 1;
    }

    int *new_array = (int *) realloc(array, (size + 1) * sizeof(int));
    if (new_array == NULL)
    {
        printf("Bo nho khong the cap phat!");
        free(array);
        return 1;
    }
    array = new_array;

    for (int i = size; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = value;
    size++;

    printf("Mang sau khi duoc chen la: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
