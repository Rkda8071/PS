#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> tp;
priority_queue<tp,vector<tp>,greater<tp> > pq;
ll hap;
ll p[10010];
ll fin(ll x){
    if(p[x] == x) return x;
    return p[x] = fin(p[x]);
}
void uni(ll x,ll y){
    x = fin(x); y = fin(y);
    p[x] = y;
}
ll v,e;
int main(){
    ll x,y,z;
    scanf("%lld %lld",&v,&e);
    for(ll i=1;i<=v;i++) p[i] = i;
    for(ll i=1;i<=e;i++){
        scanf("%lld %lld %lld",&x,&y,&z);
        pq.emplace(z,x,y);
    }
    while(!pq.empty()){
        tie(x,y,z) = pq.top(); pq.pop();
        if(fin(y) == fin(z)) continue;
        hap += x;
        uni(y,z);
    }
    printf("%lld",hap);
    return 0;
}
