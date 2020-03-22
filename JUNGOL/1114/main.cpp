#include<bits/stdc++.h>
using namespace std;
int n,dap,d1[1000],d2[1000],b,r;
char a[1000];
int main(){
    scanf("%d %s",&n,a+1);
    for(int i=1;i<=n;i++) a[n+i] = a[i];
    for(int i=1;i<=n*2;i++){
        if(a[i]=='w'){++b; ++r;}
        else if(a[i]=='r'){b=0; ++r;}
        else {++b; r=0;}
        d1[i] = max(b,r);
    }
    b=r=0;
    for(int i=n*2;i>=1;i--){
        if(a[i]=='w'){++b; ++r;}
        else if(a[i]=='r'){b=0; ++r;}
        else {++b; r=0;}
        d2[i] = max(b,r);
    }
    for(int i=1;i<n*2;i++)
        dap = max(dap,d1[i]+d2[i+1]);
    printf("%d",(n<dap)?n:dap);
    return 0;
}
