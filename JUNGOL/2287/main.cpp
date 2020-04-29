#include<bits/stdc++.h>
#define ang 1000000000
using namespace std;
typedef long long ll;
typedef tuple<ll,ll> tp;
tp a[100010],b[100010];
int n,m;
ll x,y;
multiset<ll> s;
ll solve(){
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int chk = 0;
    ll dap = 0LL;
    for(int i=1;i<=n;i++){
        x = ang - get<0>(a[i]);
        for(int j=chk+1;j<=m;j++){
            if(ang-get<0>(b[j])<x) break;
            s.insert((get<1>(b[j])));
        }
        x = get<1>(a[i]);
        if(s.empty()) return -1;
        dap += (*s.lower_bound(x));
    }
    return dap;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&x,&y);
        a[i] = tp(ang-y,x); //¸À, °ª
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld",&x,&y);
        b[i] = tp(ang-y,x);
    }
    printf("%lld",solve());
    /*for(int i=1;i<=n;i++) {
        tie(x,y) = a[i];
        printf("{%d %d}\n",ang-x,y);
    }
    for(int i=1;i<=m;i++) {
        tie(x,y) = b[i];
        printf("[%d %d]\n",ang-x,y);
    }*/
    return 0;
}
