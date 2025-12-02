#include <stdio.h>>>>>
#include <math.h>

void inputArray(int x[10], int n){
    //Nhập mảng n phần tử.
    printf("Nhập mảng x: \n");
    for(int i=0; i<n; i++){
        printf("x[%d] = ", i); scanf("%d", &x[i]);
    }
}
void showArray(int x[10], int n){
    //In ra mảng vừa nhập.
    printf("Mảng x lần lượt là: \n");
    for(int i=0; i<n; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }
}
int elementOddArray(int x[10], int n){
    //Đếm số phần tử lẻ trong mảng.
    int count = 0;
    for(int i=0; i<n; i++){
        if(x[i]%2!=0){
            count++;
        }
    }
    return count;
}
int elementEvenArray(int x[10], int n){
    //Đếm số phần tử chẵn trong mảng.
    int count = 0;
    for(int i=0; i<n; i++){
        if(x[i]%2==0){
            count++;
        }
    }
    return count;
}
int elementOddTotalArray(int x[10], int n){
    //tính tổng các phần tử lẻ.
    int sum = 0;
    for(int i=0; i<n; i++){
        if(x[i]%2!=0){
            sum = sum + x[i];
        }
    }
    return sum;
}
int elementEvenTotalArray(int x[10], int n){
    //tính tổng các phần tử chẵn.
    int sum = 0;
    for(int i=0; i<n; i++){
        if(x[i]%2==0){
            sum = sum + x[i];
        }
    }
    return sum;
}
int laSoNT(int x){
    //Kiểm tra số nguyên tố.
    int test = 1;
    if(x <= 1){
        test = 0;
    } else {
        for(int i=2; i <= sqrt(x); i++){
        if(x%i==0){
            test = 0;
            break;
        }
        }
    }
    return test;
}
int laSoCP(float x){ 
    //Kiểm tra là số chính phương.
    if(x==(int)sqrt(x) * (int)sqrt(x)){
        return 1;
    }
    else return 0;
}

int main(){
    printf("\033c");
    int x[10], n;
    printf("Nhập n: "); scanf("%d", &n);
    inputArray(x, n);
    showArray(x, n);
    printf("Các phần tử chia hết cho 3 là: ");
    int count=0;
    for(int i=0; i<n; i++){
        if(x[i]%3==0){
            printf("%d ", x[i]);
            count++;
        }
    }
    if(count == 0){
        printf("Không có!");
    }


    printf("\nSố lượng phần tử lẻ là %d\n", elementOddArray(x, n));
    printf("Số lượng phần tử chẵn là %d\n", elementEvenArray(x, n));
    printf("Tổng các phần tử lẽ là %d\n", elementOddTotalArray(x, n));
    printf("Tổng các phần tử chẵn là %d\n", elementEvenTotalArray(x, n));
    return 0;
}


