#include <stdio.h>>>>>>
#include <math.h>  // dùng cho hàm sqrt()

// Bảng MENU
void menu() {
    printf("==========================================\n");
    printf("       BẢNG MENU CHỨC NĂNG TỔNG HỢP      \n");
    printf("==========================================\n");
    printf("1. Chức năng tìm tính nguyên của một số\n");
    printf("2. Chức năng tìm UCLN và BCNN\n");
    printf("3. Chức năng tính tiền quán Karaoke\n");
    printf("4. Chức năng tính tiền điện\n");
    printf("6. Chức năng vay tiền ngân hàng\n");
    printf("8. Coming soon...\n");
    printf("0. Thoat chuong trinh\n");
    printf("------------------------------------------\n");
    printf("Moi ban chon chuc nang (0-8): ");
}

int main() { // Hàm chính
    int luachon;

    do { // Bắt đầu vòng lặp menu
        printf("\033c"); // Xóa màn hình
        menu();
        scanf("%d", &luachon);

        switch (luachon) { // dùng switch case để rẽ nhánh chia ra từng chức năng

            // CHỨC NĂNG 1: KIỂM TRA SỐ NGUYÊN TỐ 
            case 1: {
    printf("Bạn chọn CN1\n");

    float x; // dùng float để nhập số thực và số nguyên
    printf("Mời bạn nhập số x: ");
    scanf("%f", &x);

    // Kiểm tra số nguyên hay số thực
    if (x == (int)x) { // Phần thập phân bị bỏ → nếu bằng lại số cũ → là số nguyên
        int n = (int)x;
        printf("%d là số nguyên\n", n);

        // Kiểm tra số chính phương
        int sq = (int)sqrt(n); // Lấy căn bậc 2 của n
        if (sq * sq == n) { // Nếu bình phương lại bằng chính nó → chính phương
            printf("%d là số chính phương\n", n);
        }
        // VD: sqrt(25) = 5, 5*5 = 25 → chính phương
        // Kiểm tra số nguyên tố
        int isPrime = 1; // Số nguyên tố là số chỉ chia hết cho 1 và chính nó
        if (n <= 1) isPrime = 0; // 0 và 1 không phải số nguyên tố
        else {
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime) printf("%d là số nguyên tố\n", n);
        else printf("%d KHÔNG phải số nguyên tố\n", n);

    } else {
        printf("%.2f là số thực\n", x);
    }
    
    // DỪNG CHƯƠNG TRÌNH ĐỂ CHỜ NGƯỜI DÙNG
    char c;
    printf("\nNhấn phím bất kỳ để quay lại menu...");
    scanf(" %c", &c);
    break;
}

            // CHỨC NĂNG 2: UCLN & BCNN 
            case 2: {
                int a, b;
                printf("Nhập a: ");
                scanf("%d", &a);
                printf("Nhập b: ");
                scanf("%d", &b);

                int x = a, y = b;

                // Tính UCLN 
                while (x != y) {
                    if (x > y) x -= y;
                    else y -= x;
                } // Vòng lặp dừng khi x chính là UCLN.
                int ucln = x;

                // Tính BCNN 
                int bcnn = (a * b) / ucln; // Sử dụng công thức bcnn = (a * b) / ucln;

                printf("UCLN = %d\n", ucln);
                printf("BCNN = %d\n", bcnn);

    // DỪNG CHƯƠNG TRÌNH ĐỂ CHỜ NGƯỜI DÙNG
    char c;
    printf("\nNhấn phím bất kỳ để quay lại menu...");
    scanf(" %c", &c);

                break;
            }

            // CHỨC NĂNG 3: TÍNH TIỀN KARAOKE
            case 3: {
            int bd, kt;
            printf("Giờ bắt đầu (0-24): ");
            scanf("%d", &bd);
            printf("Giờ kết thúc (0-24): ");
            scanf("%d", &kt);

            // Kiểm tra giờ hợp lệ
            if (bd < 0 || bd > 24 || kt < 0 || kt > 24) {
                printf("Giờ nhập không hợp lệ! Giờ phải nằm trong khoảng 0 - 24.\n");
                break;
            }

            // Kiểm tra hợp lệ theo logic
            if (kt <= bd) { // Không thể kết thúc nhỏ hơn hoặc bằng giờ bắt đầu
                printf("Giờ kết thúc phải lớn hơn giờ bắt đầu!\n");
                break;
            }

            int sogio = kt - bd;
            float tien = 0;
            // Tính tiền Karaoke
            if (sogio <= 3) // 150.000đ/h trong 3 giờ đầu  
                tien = sogio * 150000;
            else // 120.000đ/h cho giờ thứ 4 trở đi
                tien = 3 * 150000 + (sogio - 3) * 120000;

            printf("Tiền Karaoke = %.0f VND\n", tien);

    // DỪNG CHƯƠNG TRÌNH ĐỂ CHỜ NGƯỜI DÙNG
    char c;
    printf("\nNhấn phím bất kỳ để quay lại menu...");
    scanf(" %c", &c);

            break;
        }

            // CHỨC NĂNG 4: TÍNH TIỀN ĐIỆN
            case 4: {
                int kw;
                printf("Nhập số KW tiêu thụ: ");
                scanf("%d", &kw);

                float tien = 0;

                if (kw <= 50) // 0 - 50 KW: 1678đ/KW
                    tien = kw * 1678;
                else if (kw <= 100) // 51 - 100 KW: 1734đ/KW
                    tien = 50 * 1678 + (kw - 50) * 1734;
                else // >100 KW: 2014đ/KW
                    tien = 50 * 1678 + 50 * 1734 + (kw - 100) * 2014;

                printf("Tiền điện = %.0f VND\n", tien);

    // DỪNG CHƯƠNG TRÌNH ĐỂ CHỜ NGƯỜI DÙNG
    char c;
    printf("\nNhấn phím bất kỳ để quay lại menu...");
    scanf(" %c", &c);

                break;
            }

            // CHỨC NĂNG 6: TÍNH TIỀN VAY NGÂN HÀNG (Lãi đơn)
            case 6: { // Cách tính tiền lãi = số tiền gốc × lãi suất × số tháng
                float goc, lai; // Code sử dụng lãi đơn
                int thang;

                printf("Nhập số tiền vay: ");
                scanf("%f", &goc);

                printf("Nhập lãi suất (%%/tháng): ");
                scanf("%f", &lai);

                printf("Nhập số tháng vay: ");
                scanf("%d", &thang);

                // Kiểm tra dữ liệu
                if (goc <= 0 || lai < 0 || thang <= 0) { // dùng || để kiểm tra chỉ cần 1 trong 3 dieu kien sai 
                    printf(" Dữ liệu không hợp lệ! Vui lòng nhập lại.\n");
                    break;
                }

                // Tính lãi đơn
                float tienLai = goc * (lai / 100) * thang;
                float tongTien = goc + tienLai;

                printf("Tiền lãi phải trả = %.0f VND\n", tienLai);
                printf("Tổng tiền phải trả = %.0f VND\n", tongTien);

    // DỪNG CHƯƠNG TRÌNH ĐỂ CHỜ NGƯỜI DÙNG
    char c;
    printf("\nNhấn phím bất kỳ để quay lại menu...");
    scanf(" %c", &c);

                break;
            }


            // CHỨC NĂNG 8: COMING SOON
            case 8:
                printf("Chức năng đang phát triển...\n");

    // DỪNG CHƯƠNG TRÌNH ĐỂ CHỜ NGƯỜI DÙNG
    char c;
    printf("\nNhấn phím bất kỳ để quay lại menu...");
    scanf(" %c", &c);
    
                break;

            // CHỨC NĂNG 0: THOÁT CHƯƠNG TRÌNH
            case 0:
                printf("Thoát chương trình!\n");
                break;

            // DEFAULT: LỰA CHỌN KHÔNG HỢP LỆ
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại!\n");
        }

    } while (luachon != 0); // Kết thúc vòng lặp menu

    return 0;
}









