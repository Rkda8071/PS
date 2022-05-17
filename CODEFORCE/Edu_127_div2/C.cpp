#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
int main(){
    int t;
    ll x,n,sum,day,dap;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&x);
        for(ll i=1LL;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        dap = sum = 0LL;
        day = -1LL;
        for(ll i=1LL;i<=n;i++) sum += a[i];
        for(ll i=n;i>=1LL;i--){
            if(sum<=x){
                ll ang = (x-sum)/i;
                dap += i*(ang-day);
                day = ang;
            }
            sum -= a[i];
        }
        printf("%lld\n",dap);
    }
    return 0;
}