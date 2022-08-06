#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[500010],k,m,mod = 1000000007;
ll dp[500010];
ll fac[500010];
ll f(ll x, ll y){
	if(y==0)
        return 1;
	if(y%2) 
        return (x*f(x,y-1) % mod) % mod;
	else 
        return f((x*x) % mod, y/2) % mod;
}
void init(){
    scanf("%d %lld",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        a[i] += a[i-1];
        dp[i] = 0LL;
    }
    m = a[n]/k;
    dp[0] = 1LL;
}
int main(){
    setbuf(stdout, NULL);
    int t;
    scanf("%d",&t);

    fac[0] = fac[1] = 1;
    for(ll i=1;i<=500000;i++) fac[i+1] = (fac[i] * (i+1))% mod;
    for(int tt=1;tt<=t;tt++){
        init();
        ll ans;
        if(a[n]%k != 0){
            ans = 0LL;
        }else if(m==0){
            ll ang = 0LL;
            for(int i=1;i<n;i++)
                if(a[i] == 0LL) ang++;
            --k;
            if(ang >= k)
                ans = fac[ang] * f(fac[k]*fac[ang-k]%mod, mod-2) % mod;
            else
                ans = 0LL;
        }else{
            for(int i=1;i<=n;i++){
                ll ang = a[i]/m;
                if(a[i]%m!=0 || ang <= 0 || ang>=k) continue;
                dp[ang] += dp[ang-1];
                dp[ang] %= mod;
            }
            ans = dp[k-1]%mod;
        }
        printf("Case #%d\n%lld\n",tt,ans%mod);
    }
    return 0;
}
