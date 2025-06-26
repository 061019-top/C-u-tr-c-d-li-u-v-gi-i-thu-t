#include <stdio.h>

// Hàm đệ quy tính giai thừa
int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
    int n;
    // B1: Nhập số nguyên n
    printf("Nhap so n bat ky: ");
    scanf("%d", &n);

    // B2: Gọi hàm tính giai thừa
    int res = fact(n);

    // B3: In kết quả
    printf("Giai thua cua %d la: %d\n", n, res);

    return 0;
}
