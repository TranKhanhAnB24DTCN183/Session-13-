#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void nhapMaTran(int arr[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMaTran(int arr[MAX][MAX], int n, int m) {
    printf("\nMa tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void inGoc(int arr[MAX][MAX], int n, int m) {
    printf("\nCac phan tu o goc:\n");
    printf("%d\t%d\n", arr[0][0], arr[0][m-1]);
    printf("%d\t%d\n", arr[n-1][0], arr[n-1][m-1]);
}

void inDuongBien(int arr[MAX][MAX], int n, int m) {
    printf("\nCac phan tu tren duong bien:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                printf("%d\t",arr[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

void inDuongCheo(int arr[MAX][MAX], int n, int m) {
    printf("\nCac phan tu tren duong cheo chinh va cheo phu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j || i + j == m - 1) {
                printf("%d\t", arr[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

bool laSoNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void inSoNguyenTo(int arr[MAX][MAX], int n, int m) {
    printf("\nCac phan tu la so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laSoNguyenTo(arr[i][j])) {
                printf("%d\t", arr[i][j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}


int main() {
    int arr[MAX][MAX];
    int n, m, choice;

    printf("Nhap so hang (n): ");
    scanf("%d", &n);
    printf("Nhap so cot (m): ");
    scanf("%d", &m);

    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMaTran(arr, n, m);
                break;
            case 2:
                inMaTran(arr, n, m);
                break;
            case 3:
                inGoc(arr, n, m);
                break;
            case 4:
                inDuongBien(arr, n, m);
                break;
            case 5:
                inDuongCheo(arr, n, m);
                break;
            case 6:
                inSoNguyenTo(arr, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le.Vui long thu lai\n");
        }
    } while (choice != 7);

    return 0;
}

