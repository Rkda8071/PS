#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll> tp;

ll n,l,dap;
ll x,y;
ll d[100100][2]; // [index][0이면 top, 1이면 bottom]
tp a[100100];
set<tp> ms;
int main(){
    scanf("%lld %lld",&n,&l);
    a[0] = tp(-1,-1);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&x,&y);
        a[i] = tp(x,y);
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        ll t,b;
        tie(t,b) = a[i];
        d[i][0] = d[i][1] = l+abs(t-b);

        if(get<0>(a[i-1]) == t){ //만약 이전 막대기랑 top에서 겹친다
            d[i][0] = max(d[i][0],d[i-1][0]);
            d[i][1] += d[i-1][0];// + l+abs(t-b);
        } //문제 X

        if(!ms.empty()){
            auto it = ms.lower_bound(tp(b,0));
            tie(y,x) = *it;
            if(y!=b)
                ms.insert(tp(b,i));

            else{
                if(d[i][0]<d[x][1]+l+abs(t-b))
                    d[i][0] = d[x][1]+l+abs(t-b);

                if(d[x][1]<d[i][1])
                    d[x][1] = d[i][1];
            }

        }else ms.insert(tp(b,i));
        dap = max(dap,max(d[i][1],d[i][0]));
    }
    printf("%lld",dap);
    return 0;
}
