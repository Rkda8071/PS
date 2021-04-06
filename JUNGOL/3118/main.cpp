#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll> tp;
int n,m;
ll d[100010];
vector<tp> a[100010];
priority_queue<tp,vector<tp>,greater<tp> > pq;
void init(){
    ll x,y,z;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%lld %lld %lld",&x,&y,&z);
        a[x].push_back(tp(y,z));
    }
    for(int i=2;i<=n;i++) d[i] = 200000000000;
}
int main(){
    ll x,y,xx,yy;
    init();
    pq.emplace(0,1);
    while(!pq.empty()){
        tie(y,x) = pq.top(); pq.pop();
        if(d[x] != y) continue;
        for(int i=0;i<a[x].size();i++){
            tie(xx,yy) = a[x][i];
            if(d[xx]>yy+y){
                d[xx] = yy+y;
                pq.emplace(d[xx],xx);
            }
        }
    }
    printf("%lld",d[n]);
    return 0;
}
