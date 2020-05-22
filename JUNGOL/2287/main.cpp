#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll> tp;
int n,m;
tp a[100100],g[100100];
multiset<ll> s;
ll x,y,dap;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&x,&y); //값, 맛
        a[i] = tp(2000000000LL-y,x);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld",&x,&y);
        g[i] = tp(y,x);
    }
    // [ 맛, 값 ]
    sort(a+1,a+n+1);
    sort(g+1,g+m+1);
    for(int i=1;i<=n;i++){
        tie(y,x) = a[i];
        while(m>0 && get<0>(g[m])>=2000000000LL-y){
            s.insert(get<1>(g[m]));
            --m;
        }
        if(s.size() == 0){
            dap = -1;
            break;
        }
        auto j = s.lower_bound(x);
        if(*j >= x) dap += *j;
        else{
            if(++j == s.end()){
                dap = -1;
                break;
            }
            dap += *j;
        }
        s.erase(j);
    }
    printf("%lld",dap);
    return 0;
}
