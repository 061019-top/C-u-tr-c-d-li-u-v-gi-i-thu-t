#include <stdio.h>

int main() {
    int size;
    // B1: Khai báo biến lưu số phần tử của mảng
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);

    int array[size];
    // B2: Khai báo mảng 'array' có 'size' phần tử
    for (int i = 0; i < size; i++) {
        // B3: Sử dụng vòng lặp để nhập giá trị từng phần tử của mảng
        printf("phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++) {
        // B4: Sử dụng vòng lặp để in ra các phần tử của mảng
        printf("%d ", array[i]);
    }
    printf("\n");

    // B5: Tạo biến 'max' và gán giá trị đầu tiên của mảng vào
    int max = array[0];
    int maxIndex = 0;

    // B6: Sử dụng vòng lặp để tìm phần tử lớn nhất đầu tiên trong mảng
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }
    }

    // B7: In ra kết quả là chỉ số của phần tử lớn nhất đầu tiên
    printf("Chi so phan tu lon nhat dau tien trong mang: %d\n", maxIndex);

    return 0;
}

