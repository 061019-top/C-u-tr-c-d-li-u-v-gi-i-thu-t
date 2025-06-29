//
// Created by ADMIN on 6/29/2025.
//
#include <stdio.h>

// Hàm giải bài toán Tháp Hà Nội bằng đệ quy
void tower(int n, char start, char mid, char end) {
    if (n == 1) {
        printf("Dia 1 di chuyen tu %c sang %c\n", start, end);
        return;
    }
    // B1: Di chuyển n-1 đĩa từ cột đầu sang cột trung gian
    tower(n - 1, start, end, mid);
    // B2: Di chuyển đĩa thứ n từ cột đầu sang cột đích
    printf("Dia %d di chuyen tu %c sang %c\n", n, start, end);
    // B3: Di chuyển n-1 đĩa từ cột trung gian sang cột đích
    tower(n - 1, mid, start, end);
}

int main() {
    int n;

    // Nhập số lượng đĩa
    printf("Nhap so luong dia: ");
    scanf("%d", &n);

    // Kiểm tra đầu vào
    if (n <= 0) {
        printf("So luong dia khong hop le!\n");
        return 1;
    }

    // Gọi hàm giải Tháp Hà Nội
    tower(n, 'A', 'B', 'C');

    return 0;
}
