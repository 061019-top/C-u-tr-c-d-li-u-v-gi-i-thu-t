#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Nhap so phan tu trong mang : ");
    scanf("%d",&n);

    if(n<=0) {
        printf("So luong phan tu khong hop le");
        return -1;
    }

    int *arr=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        printf("Nhap phan tu %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        printf("So tu %d = %d \n",i+1,arr[i]);
    }
    free(arr);
    return 0;
}