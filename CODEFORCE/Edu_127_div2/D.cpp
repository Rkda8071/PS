#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        ll n,x,mini,maxim,dap=0LL;
        scanf("%lld %lld",&n,&x);
        for(ll i=1LL;i<=n;i++) scanf("%lld",&a[i]);
        for(ll i=2LL;i<=n;i++) dap += abs(a[i]-a[i-1]);
        mini = maxim = a[1];
        for(ll i=2LL;i<=n;i++){
            mini = min(mini, a[i]);
            maxim = max(maxim, a[i]);
        }

        dap += min(a[n]-1LL, min(a[1] - 1LL, 2LL*(mini - 1LL)));
        if(x > maxim){
            dap += min(x-a[n], min(2LL*(x - maxim), x-a[1]));
        }
        printf("%lld\n",dap);
    }
    return 0;
}