#include<bits/stdc++.h>
using namespace std;
char a[20],ang[20];
int chk[30],n,cnt,dap;
void f(int x,char b){
    if(x==n) {dap++; return;}
    for(int i=1;i<=cnt;i++){
        if(b!=ang[i] && chk[ang[i]-'0']){
            --chk[ang[i]-'0'];
            f(x+1,ang[i]);
            ++chk[ang[i]-'0'];
        }
    }
}
int main(){
    scanf("%s",a+1);
    for(int i=1;a[i]!=NULL;i++){
        if(chk[a[i]-'0']++ == 0) ang[++cnt] = a[i];
        n++;
    }
    f(0,0);
    printf("%d",dap);
    return 0;
}
