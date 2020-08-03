#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200100],b[200100],chk[200100];
ll cnt[200100];
int fin(int x){
    if(chk[x] == x) return x;
    return chk[x] = fin(chk[x]);
}
void uni(int x,int y){
    x = fin(x); y = fin(y);
    chk[x] = y;
    return;
}
ll f(ll x){ return x*(x-1)/2; }
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) chk[i] = i;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(j-i<=a[i]+b[j] && j-i<=a[j]+b[i])
                uni(i,j);
    for(int i=1;i<=n;i++) cnt[fin(i)]++;
    for(int i=1;i<=n;i++)
        cnt[0] += f(cnt[i]);
    printf("%lld",cnt[0]);
    return 0;
}
