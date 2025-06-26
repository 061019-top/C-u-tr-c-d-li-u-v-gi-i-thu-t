#include <stdio.h>

// Hàm đệ quy tính tổng từ 1 đến k
int sum(int k) {
    if (k == 1) {
        return 1;
    }
    return k + sum(k - 1);
}

int main() {
    int n;
    // B1: Nhập số nguyên n
    printf("Nhap so n bat ky: ");
    scanf("%d", &n);

    // B2: Gọi hàm đệ quy để tính tổng từ 1 đến n
    int res = sum(n);

    // B3: In kết quả ra màn hình
    printf("Tong tu 1 den %d la: %d\n", n, res);

    return 0;
}
