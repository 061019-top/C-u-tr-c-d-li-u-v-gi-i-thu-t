//
// Created by ADMIN on 6/29/2025.
//
#include <stdio.h>

// Hàm đệ quy tìm phần tử lớn nhất
int findMax(int arr[], int n, int index) {
    // Điều kiện dừng: nếu đến phần tử cuối cùng
    if (index == n - 1) {
        return arr[index];
    }
    // Gọi đệ quy với phần tử tiếp theo
    int max = findMax(arr, n, index + 1);
    // So sánh và trả về giá trị lớn hơn
    return arr[index] > max ? arr[index] : max;
}

// Hàm đệ quy tìm phần tử nhỏ nhất
int findMin(int arr[], int n, int index) {
    // Điều kiện dừng: nếu đến phần tử cuối cùng
    if (index == n - 1) {
        return arr[index];
    }
    // Gọi đệ quy với phần tử tiếp theo
    int min = findMin(arr, n, index + 1);
    // So sánh và trả về giá trị nhỏ hơn
    return arr[index] < min ? arr[index] : min;
}

int main() {
    int n;
    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    // Nhập giá trị từng phần tử
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In toàn bộ mảng
    printf("Mang vua nhap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Tìm giá trị lớn nhất và nhỏ nhất bằng đệ quy
    int max = findMax(arr, n, 0);
    int min = findMin(arr, n, 0);

    // In kết quả
    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);

    return 0;
}
