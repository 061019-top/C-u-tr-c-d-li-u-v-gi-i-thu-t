#include <stdio.h>

int main() {
    int size;
    // B1: Khai báo biến 'size' để lưu số lượng phần tử của mảng
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &size);

    int array[size];
    // B2: Khai báo mảng 'array' có 'size' phần tử
    for (int i = 0; i < size; i++) {
        printf("phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    // B3: Sắp xếp mảng bằng thuật toán Bubble Sort (sắp xếp nổi bọt)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        // B4: In ra mảng sau khi sắp xếp
        printf("%d ", array[i]);
    }
    printf("\n");

    int target;
    // B5: Khai báo biến 'target' để lưu giá trị cần tìm
    printf("Nhap gia tri bat ky: ");
    scanf("%d", &target);

    int foundIndex = -1;
    // B6: Khai báo biến 'foundIndex' để lưu kết quả tìm kiếm
    int left = 0, right = size - 1;
    // B7: Thực hiện tìm kiếm nhị phân (binary search)
    while (left <= right) {
        int mid = (left + right) / 2; // Tính chỉ số giữa
        if (array[mid] == target) {
            foundIndex = mid;
            break;
        } else if (array[mid] < target) {
            left = mid + 1; // Giá trị cần tìm nằm bên phải
        } else {
            right = mid - 1; // Giá trị cần tìm nằm bên trái
        }
    }

    // B8: In ra kết quả tìm kiếm
    if (foundIndex != -1) {
        printf("Phan tu co trong mang");
    } else {
        printf("Phan tu khong co trong mang");
    }

    return 0;
}

