//
// Created by ADMIN on 6/29/2025.
//
#include <stdio.h>

// Hàm đệ quy tính tổng các chữ số của n
int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sum(n / 10);
}

int main() {
    int n;
    // B1: Nhập số nguyên dương n
    printf("Nhap so n bat ky: ");
    scanf("%d", &n);

    // B2: Kiểm tra điều kiện hợp lệ
    if (n < 0) {
        printf("So nhap vao khong hop le!\n");
    } else {
        // B3: Gọi hàm và in kết quả
        int result = sum(n);
        printf("Tong cac chu so cua %d la: %d\n", n, result);
    }

    return 0;
}
