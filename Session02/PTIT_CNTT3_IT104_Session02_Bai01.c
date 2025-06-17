#include <stdio.h>

int main() {
    int soPhanTu;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &soPhanTu);

    if (soPhanTu <= 0 || soPhanTu > 100) {
        printf("So phan tu khong hop le!");
        return 1;
    }

    int mangSoNguyen[soPhanTu];
    for (int i = 0; i < soPhanTu; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &mangSoNguyen[i]);
    }

    int giaTriLonNhat = mangSoNguyen[0];
    for (int i = 1; i < soPhanTu; i++) {
        if (mangSoNguyen[i] > giaTriLonNhat) {
            giaTriLonNhat = mangSoNguyen[i];
        }
    }

    printf("Phan tu lon nhat trong mang la: %d\n", giaTriLonNhat);
    return 0;
}

