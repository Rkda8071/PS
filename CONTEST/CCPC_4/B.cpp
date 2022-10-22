#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    n -= 1023;
    if(n <= 0){
        printf("No thanks");
    }else{
        if((n & m) == n)
            printf("Thanks");
        else
            printf("Impossible");
    }
}