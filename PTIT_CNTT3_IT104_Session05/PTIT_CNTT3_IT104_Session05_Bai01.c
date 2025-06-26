#include <stdio.h>

// Hàm đệ quy in ra dãy số từ 1 đến n
void printUp(int n, int i) {
    if (i > n) return;
    printf("%d ", i);
    printUp(n, i + 1);
}

int main() {
    int n;
    // B1: Nhập số nguyên n
    printf("Nhap so n bat ky: ");
    scanf("%d", &n);

    // B2: Gọi hàm in từ 1 đến n
    printUp(n, 1);

    return 0;
}
