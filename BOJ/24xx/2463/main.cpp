#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tp;
tp a[100010];
ll s[100010],cur,dap;
int d[100010],n,m;
int fin(int x){
    if(d[x]==x) return x;
    return d[x] = fin(d[x]);
}
void uni(int x,int y){
    x = fin(x); y = fin(y);
    if(x!=y){
        dap = (dap + s[x]*s[y]*cur) % 1000000000LL;
        d[y] = x;
        s[x] += s[y];
    }
}
int main(){
    int x,y;
    ll z;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %lld",&x,&y,&z);
        if(x>y) swap(x,y);
        a[i] = tp(z,x,y);
        cur += z;
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++) {d[i] = i; s[i] = 1LL;}
    for(int i=m;i>=1;i--){
        tie(z,x,y) = a[i];
        uni(x,y);
        cur -= z;
    }
    printf("%lld",dap);
    return 0;
}
