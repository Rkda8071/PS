#include<bits/stdc++.h>
using namespace std;
int a[1010],chk[1010];
int s[1000],cnt;
void f(int x){
    for(int j=3;j*j<=x;j+=2)
        if(x%j==0) return;
    s[++cnt] = x;
}
int main(){
    int t;
    scanf("%d",&t); ++t;
    s[++cnt] = 2;
    for(int i=3;i<=1000;i+=2)
        f(i);

    while(--t){
        int n,m=0,col[1010]={0};
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    }
    return 0;
}
