#include <stdio.h>


int findUcln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b, c; 

    printf("Nhap so nguyen a: ");
    scanf("%d", &a);
    printf("Nhap so nguyen b: ");
    scanf("%d", &b);
    printf("Nhap so nguyen c: ");
    scanf("%d", &c);

    int ucln_abc = findUcln(findUcln(a, b), c);

    printf("Uoc chung lon nhat (UCLN) la: %d\n", ucln_abc);

    return 0;
}

