#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll a[600010],b[600010],d[600010],dap;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i],&b[i]);
        for(int i=1;i<=n;i++) {a[i+n] = a[i]; b[i+n] = b[i];}
        for(int i=2;i<=n*2;i++){
            d[i] = max(0LL,a[i]-b[i-1]);
            d[i] += d[i-1];
        }
        dap = 2000000000000000000LL;
        for(int i=n;i<n*2;i++)
            dap = min(dap,d[i]-d[i-n+1]+a[i-n+1]);
        printf("%lld\n",dap);
    }
    return 0;
}
