#include <stdio.h>
#include <math.h>

int main() {
    int x, i, dem = 0;
    printf("Nhap so x: ");
    scanf("%d", &x);

    if (x < 2) {
        printf("%d khong phai la so nguyen to.\n", x);
    } else {
        for (i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                dem++;
                break;
            }
        }
    }
        if (dem == 0){
            printf("%d la so nguyen to.\n", x);
        }
        else{
            printf("%d không phải là số nguyên tố.", x);               
        }
}
