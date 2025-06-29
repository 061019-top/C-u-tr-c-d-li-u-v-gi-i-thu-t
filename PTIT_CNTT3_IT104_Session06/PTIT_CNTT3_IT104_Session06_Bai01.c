v//
// Created by ADMIN on 6/29/2025.
//
#include <stdio.h>

// Hàm đệ quy để in ra dạng nhị phân của số nguyên dương
void convertBinary(int n) {
    if (n == 0) {
        return;
    }
    convertBinary(n / 2);         // Gọi lại hàm với phần nguyên
    printf("%d", n % 2);          // In phần dư (bit nhị phân)
}

int main() {
    int n;

    // B1: Nhập số nguyên dương
    printf("Nhap so nguyen duong bat ky: ");
    scanf("%d", &n);

    // B2: Kiểm tra hợp lệ
    if (n <= 0) {
        printf("So nhap vao khong hop le!\n");
    } else {
        // B3: Gọi hàm chuyển và in kết quả
        printf("Dang nhi phan: ");
        convertBinary(n);
        printf("\n");  // Xuống dòng sau kết quả
    }

    return 0;
}
