#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A{
    ll x,y;
}a[100],X,Y;
int n;
ll f(A x,A y,A z){return (y.y - x.y)*(z.x-x.x) - (z.y - x.y) * (y.x - x.x); }
void solve(){
    int dap = 0;
    ll x,y;
    for(int i=1;i<n;i++){
        x = f(X,Y,a[i])*f(X,Y,a[i+1]);
        y = f(a[i],a[i+1],X)*f(a[i],a[i+1],Y);
        if((x == 0L && y<=0L) || (x<=0L && y == 0L)){
            printf("BOUNDARY");
            return;
        }
        else if(x<0 && y<0) dap++;
    }

    x = f(X,Y,a[1])*f(X,Y,a[n]);
    y = f(a[1],a[n],X)*f(a[1],a[n],Y);
    if((x == 0L && y<=0L) || (x<=0L && y == 0L)){
        printf("BOUNDARY");
        return;
    }
    else if(x<0L && y<0L) dap++;

    if(dap%2) printf("INTERIOR");
    else printf("EXTERIOR");
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
    scanf("%lld %lld",&X.x,&X.y);
    Y = {1111111L,X.y + 1L};
    solve();
    return 0;
}
