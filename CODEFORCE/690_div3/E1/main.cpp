#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200100];
ll f(int x){
    ll dap = 0LL;
    // x에서 1개
    if(a[x]>=1LL){
        // 2,0
        if(a[x+1]>=2LL) dap += a[x]*(a[x+1]*(a[x+1]-1LL))/2LL;
        // 1,1
        if(a[x+1]>=1LL && a[x+2]>=1LL) dap+=a[x]*a[x+1]*a[x+2];
        // 0,2
        if(a[x+2]>=2LL) dap += a[x]*(a[x+2]*(a[x+2]-1LL))/2LL;
    }
    // x에서 2개
    if(a[x]>=2LL){
        // 1,0
        if(a[x+1]>=1LL) dap += a[x+1]*(a[x]*(a[x]-1LL))/2LL;
        // 0,1
        if(a[x+2]>=1LL) dap += a[x+2]*(a[x]*(a[x]-1LL))/2LL;
    }
    // x에서 3개
    if(a[x]>=3LL){
        // 0,0
        dap += (a[x]*(a[x]-1LL)*(a[x]-2LL))/6LL;
    }
    return dap;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll ddd = 0LL;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) a[i] = 0LL;
        for(int i=1;i<=n;i++){
            int ang; scanf("%d",&ang);
            a[ang]++;
        }
        for(int i=1;i<=n;i++)
            ddd += f(i);
        printf("%lld\n",ddd);
    }
    return 0;
}
