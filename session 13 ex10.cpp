#include <stdio.h>

#define MAX 100
int n;
void nhapMang(int arr[]) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    for (int i = 0; i <n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void inMang(int arr[]) {
    printf("\nCac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t ", arr[i]);
    }
    printf("\n");
}

void themPhanTu(int arr[], int value, int pos) {
    if (pos < 0 || pos > n ) {
        printf("Vi tri khong hop le \n");
        return  ;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
       for (int i = 0; i < n; i++) {
        printf("%d\t ", arr[i]);
    }
}

void suaPhanTu(int arr[], int value, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    arr[pos] = value;
    printf("Sua phan tu thanh cong.\n");
     for (int i = 0; i < n; i++) {
        printf("%d\t ", arr[i]);
    }
}
void xoaPhanTu(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Xoa phan tu thanh cong.\n");
}


void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep tang dan thanh cong.\n");
}

void sapXepGiamDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep giam dan thanh cong.\n");
}

void timTuyenTinh(int arr[], int n, int value) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Phan tu %d tim thay o vi tri %d.\n", value, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", value);
    }
}

void timNhiPhan(int arr[], int n, int value) {
    sapXepTangDan(arr, n); 
    int left = 0, right = n - 1, mid, found = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == value) {
            printf("Phan tu %d tim thay o vi tri %d.\n", value, mid);
            found = 1;
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", value);
    }
}


int main() {
    int arr[100];
    int n , choice, value, pos;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("   a. Giam dan\n");
        printf("   b. Tang dan\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("   a. Tim kiem tuyen tinh\n");
        printf("   b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr);
                break;
            case 2:
                inMang(arr);
                break;
            case 3:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                themPhanTu(arr, value, pos);
                break;
            case 4:
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                suaPhanTu(arr, value, pos);
                break;
            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                xoaPhanTu(arr, n, pos);
                break;
            case 6:
                printf("Chon kieu sap xep (1: Giam dan, 2: Tang dan): ");
                scanf("%d", &value);
                if (value == 1)
                    sapXepGiamDan(arr, n);
                else if (value == 2)
                    sapXepTangDan(arr, n);
                else
                    printf("Lua chon khong hop le.\n");
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                printf("Chon phuong phap tim kiem (1: Tuyen tinh, 2: Nhi phan): ");
                scanf("%d", &pos);
                if (pos == 1)
                    timTuyenTinh(arr, n, value);
                else if (pos == 2)
                    timNhiPhan(arr, n, value);
                else
                    printf("Lua chon khong hop le.\n");
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 8);

    return 0;
}

