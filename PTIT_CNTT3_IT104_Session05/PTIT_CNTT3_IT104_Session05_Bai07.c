#include <stdio.h>
#include <stdlib.h>

// Hàm đệ quy tính số Fibonacci thứ n
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    // B1: Nhập số lượng số Fibonacci cần in
    printf("Nhap so luong so fibonacci ban muon: ");
    scanf("%d", &n);

    // B2: Kiểm tra điều kiện hợp lệ
    if (n <= 0) {
        printf("So khong hop le!\n");
        return -1;
    }

    // B3: Cấp phát động bộ nhớ cho mảng
    int *fib = (int *)malloc(n * sizeof(int));
    if (fib == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return -1;
    }

    // B4: Gán giá trị Fibonacci vào mảng
    for (int i = 0; i < n; i++) {
        fib[i] = fibonacci(i);
    }

    // B5: In kết quả
    printf("Day Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // B6: Giải phóng bộ nhớ
    free(fib);
    return 0;
}

