#include<stdio.h>
int a = 5;
int func(){
    int a = 4;
    return a;
}
int main(){
    int a = 3;
    printf("%d %d %d",a, func(), a);
}