#include<bits/stdc++.h>
using namespace std;
char b[10]={0};
int a,c=(1<<8)-1;

int main(){
    scanf("%s",b+1);
    for(int i=1;i<=8;i++){
        a *= 2;
        a += ((b[i]=='1') ? 1 : 0);
    }
    if(a&(1<<7)) printf("%d",(-1)*(c^(a-1)));
    else printf("%d",a);
    return 0;
}
