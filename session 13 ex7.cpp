#include <stdio.h>

#define MAX_HANG 100 
#define MAX_COT 100 


void taoMaTran(int arr[MAX_HANG][MAX_COT], int soHang, int soCot) {
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMaTran(int arr[MAX_HANG][MAX_COT], int soHang, int soCot) {
    printf("\nMa tran vua nhap la:\n");
    for (int i = 0; i < soHang; ++i) {
        for (int j = 0; j < soCot; ++j) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int soHang, soCot;
    int arr[MAX_HANG][MAX_COT]; 

    printf("Nhap so hang cua ma tran : ");
    scanf("%d", &soHang);
    printf("Nhap so cot cua ma tran : ");
    scanf("%d", &soCot);

    if (soHang > 0 && soHang <= MAX_HANG && soCot > 0 && soCot <= MAX_COT) {
        taoMaTran(arr, soHang, soCot);
        
        inMaTran(arr, soHang, soCot);
    } else {
        printf("So hang va so cot khong hop le. Vui long nhap so trong khoang phu hop!");
    }

    return 0;
}

