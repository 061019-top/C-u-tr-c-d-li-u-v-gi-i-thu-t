
#include <stdio.h>
#include <string.h>

// Hàm đệ quy kiểm tra chuỗi có đối xứng không
int isSymmetric(char str[], int left, int right) {
    if (left >= right) {
        return 1; // Chuỗi đối xứng
    }
    if (str[left] != str[right]) {
        return 0; // Không đối xứng
    }
    return isSymmetric(str, left + 1, right - 1);
}

int main() {
    char str[100];

    // Nhập chuỗi
    printf("Nhap mot chuoi bat ky: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Xoá ký tự newline

    int len = strlen(str);
    int res = isSymmetric(str, 0, len - 1);

    // In kết quả
    if (res == 1) {
        printf("La chuoi doi xung!\n");
    } else {
        printf("Chuoi khong doi xung!\n");
    }

    return 0;
}
