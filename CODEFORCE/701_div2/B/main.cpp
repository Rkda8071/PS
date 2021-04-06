#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,k;
ll a[100010],cnt[100010];
int main(){
    scanf("%d %d %d",&n,&q,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    a[n+1] = (ll)(k+1);

    for(int i=1;i<=n;i++) cnt[i] = a[i+1] - a[i-1] - 2LL;
    for(int i=1;i<=n;i++) cnt[i] += cnt[i-1];

    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        ll dap = (a[l] - 1LL + ((ll)(k) - a[r])) + cnt[r-1] - cnt[l];
        if(l!=r) dap += a[l+1]-a[l]-1LL + a[r]-a[r-1]-1LL;
        else dap = (ll)(k-1);
        printf("%lld\n",dap);
    }
    return 0;
}
