//
// Created by ADMIN on 6/30/2025.
//
#include <stdio.h>
#include <string.h>

// Hàm sắp xếp các ký tự trong chuỗi theo thứ tự tăng dần (Bubble Sort)
void sortString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j]; // sửa thành char
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[100];

    // Nhập chuỗi từ người dùng
    printf("Nhap vao chuoi ky tu bat ky: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Loại bỏ ký tự newline nếu có

    // Kiểm tra chuỗi có toàn khoảng trắng hoặc rỗng
    int isEmpty = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            isEmpty = 0;
            break;
        }
    }

    if (isEmpty) {
        printf("Chuoi khong hop le\n");
        return 0;
    }

    printf("Chuoi ban dau: %s\n", str);

    // Sắp xếp chuỗi
    sortString(str);

    printf("Chuoi sau khi sap xep: %s\n", str);

    return 0;
}
