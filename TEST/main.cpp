#include<stdio.h>

void myswap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int main(){
    int a,b;
    a = 3; b = 5;
    printf("%d %d\n",a,b);
    myswap(a,b);
    printf("%d %d",a,b);
}