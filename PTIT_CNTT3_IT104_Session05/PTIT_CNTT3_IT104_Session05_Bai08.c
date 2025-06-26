#include <stdio.h>

// Hàm kiểm tra chuỗi chỉ chứa ký tự số (0-9)
int isValidNumber(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0; // Không hợp lệ
        }
        i++;
    }
    return 1; // Hợp lệ
}

// Hàm đệ quy chuyển chuỗi số thành số nguyên
int toInteger(char str[], int index, int value) {
    if (str[index] == '\0') {
        return value;
    }
    return toInteger(str, index + 1, value * 10 + (str[index] - '0'));
}

int main() {
    char str[100];

    // B1: Nhập chuỗi ký tự
    printf("Nhap chuoi ky tu bat ky: ");
    scanf("%s", str);

    // B2: Kiểm tra tính hợp lệ của chuỗi
    if (!isValidNumber(str)) {
        printf("Chuoi khong hop le!\n");
        return 0;
    }

    // B3: Chuyển đổi chuỗi thành số nguyên bằng đệ quy
    int result = toInteger(str, 0, 0);

    // B4: In kết quả
    printf("%d\n", result);

    return 0;
}
