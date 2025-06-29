//
// Created by ADMIN on 6/29/2025.
//
#include <stdio.h>

// Hàm đệ quy tính số cách leo n bậc thang
int count(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    return count(n - 1) + count(n - 2);
}

int main()
{
    int n;
    // B1: Nhập số bậc thang
    printf("Nhap so bac thang: ");
    scanf("%d", &n);

    // B2: Kiểm tra điều kiện
    if (n < 0)
    {
        printf("So nhap vao khong hop le!\n");
        return 1;
    }

    // B3: Tính số cách leo
    int result = count(n);
    printf("So cach de leo %d bac la: %d\n", n, result);

    return 0;
}
