#include <stdio.h>>>>>>>>>>>
#include <math.h>

// 1. Nhập vào một số nguyên từ bàn phím (sử dụng con trỏ để lưu giá trị)
void nhapSoNguyen(int *n) {
    printf("Nhap mot so nguyen: ");
    scanf("%d", n);
}

// 2. Nhập vào một số thực (thập phân) từ bàn phím (sử dụng con trỏ)
void nhapSoThapPhan(float *x) {
    printf("Nhap mot so (thap phan): ");
    scanf("%f", x);
}

// 3. Trả về 1 nếu x là số nguyên, ngược lại 0
int laSoNguyen(float x) {
    if (x == (int)x)
        return 1;
    return 0;
}

// 4. Trả về 1 nếu x là số chính phương, ngược lại 0
int laSoCP(float x) {
    if (x < 0 || x != (int)x) return 0;   // không âm + phải nguyên

    int k = sqrt((int)x);    // Sử dụng hàm sqrt từ thư viện math.h
    if (k * k == (int)x)
        return 1;
    return 0;
}

// 5. Trả về 1 nếu x là số nguyên tố, ngược lại 0
int laSoNT(float x) {
    if (x != (int)x || x < 2) return 0;   // phải là số nguyên >= 2

    int n = (int)x;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    float x;

    // Test từng hàm
    nhapSoNguyen(&n);
    nhapSoThapPhan(&x);

    printf("\n--- KET QUA KIEM TRA ---\n");

    printf("%.2f %s so nguyen\n", x, laSoNguyen(x) ? "la" : "khong la");
    printf("%d %s so chinh phuong\n", n, laSoCP(n) ? "la" : "khong la");
    printf("%d %s so nguyen to\n", n, laSoNT(n) ? "la" : "khong la");

    return 0;
}
