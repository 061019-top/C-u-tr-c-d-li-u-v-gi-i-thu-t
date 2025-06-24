#include <stdio.h>
#include <stdlib.h>

int main() {
    int **a = NULL, dong, cot;
    printf("Nhap vao so dong=");
    scanf("%d", &dong);
    printf("Nhap vao so cot=");
    scanf("%d", &cot);

    if (dong<=0) {
        printf("Khong hop le\n");
        return -1;
    }else if (cot<=0) {
        printf("Khong hop le\n");
        return -1;
    }
    a = (int **)malloc(dong * sizeof(int *));
    for (int i = 0; i < dong; i++){
        a[i] = (int *)malloc(cot * sizeof(int));
    }

    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            printf("arr[%d][%d]=:", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i=0;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            printf("arr[%d][%d]=%d \n", i, j,a[i][j]);
        }
    }
    int k;
    int sum=0;

    printf("Hang can tinh :");
    scanf("%d",&k);

    if (k>dong) {
        printf("Hang can tinh khong ton tai\n");
        return -1;
    }

    for (int i=k-1;i<dong;i++) {
        for (int j=0;j<cot;j++) {
            sum+=a[i][j];
        }
    }
    printf("Tong cac phan tu cua hang %d la %d",k,sum);

    for (int i = 0; i < dong; i++){
        free(a[i]);
    }
    free(a);
    return 0;
}