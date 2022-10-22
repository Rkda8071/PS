#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100100],n,t,dap;
vector<int> p[100100];
ll f(int x){
    ll mini = 2000000000LL,sum=0LL;
    for(auto y : p[x]){
        ll ang = f(y);
        mini = min(ang,mini);
        sum += ang;
    }
    if(x == 0) return sum;
    if(mini == 2000000000LL) mini = 0LL;
    dap += sum - mini;
    return max(a[x],mini);
}
int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        dap = 0LL;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=0;i<=n;i++) p[i].clear();
        for(int x,i=1;i<=n;i++){
            scanf("%d",&x);
            p[x].push_back(i);
        }
        dap += f(0);
        printf("Case #%d: %lld\n",tt,dap);
    }
}
