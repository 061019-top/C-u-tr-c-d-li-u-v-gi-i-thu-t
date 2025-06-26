#include <stdio.h>

// Hàm đệ quy tính tổng từ số đầu đến số cuối
int sum(int a, int b) {
    if (a > b) {
        return 0;
    }
    if (a == b) {
        return a;
    }
    return a + sum(a + 1, b);
}

int main() {
    int a, b;
    // B1: Nhập 2 số nguyên
    printf("Moi ban nhap so thu 1: ");
    scanf("%d", &a);
    printf("Moi ban nhap so thu 2: ");
    scanf("%d", &b);

    // B2: Gọi hàm để tính tổng từ a đến b
    int res = sum(a, b);

    // B3: In kết quả
    printf("Tong tu %d den %d la: %d\n", a, b, res);

    return 0;
}
