#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll> tp;
int n;
ll a[3010],maxim;
vector<tp> d[3010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);

    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            ll dis = a[i] - a[j];
            auto x = lower_bound(d[j].begin(),d[j].end(),tp(dis,0LL));
            if(x==d[j].end() || get<0>(*x) != dis){
                d[i].push_back(tp(dis,a[i]+a[j]));
            }else{
                ll xx,yy;
                tie(xx,yy) = *x;
                d[i].push_back(tp(dis,yy+a[i]));
                maxim = max(maxim,yy+a[i]);
            }
        }
    }
    printf("%lld",maxim);
}
