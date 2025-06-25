#include <stdio.h>

int main() {
    int size;
    // B1: Khai báo biến lưu số phần tử của mảng
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);

    int array[size];
    // B2: Khai báo mảng 'array' có 'size' phần tử
    for (int i = 0; i < size; i++) {
        // B3: Sử dụng vòng lặp để nhập giá trị từng phần tử
        printf("phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++) {
        // B4: Sử dụng vòng lặp để in ra các phần tử
        printf("%d ", array[i]);
    }
    printf("\n");

    // B5: Tạo biến 'min' và gán giá trị đầu tiên của mảng
    int min = array[0];
    int minIndex = 0; // chỉ số đầu tiên là vị trí của phần tử nhỏ nhất tạm thời

    for (int i = 1; i < size; i++) {
        // B6: Duyệt mảng để tìm phần tử nhỏ nhất đầu tiên
        if (array[i] < min) {
            min = array[i];
            minIndex = i;
        }
    }

    // B7: In ra kết quả là chỉ số phần tử nhỏ nhất đầu tiên trong mảng
    printf("chi so phan tu nho nhat dau tien trong mang: %d\n", minIndex);

    return 0;
}
