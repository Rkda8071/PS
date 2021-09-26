#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll> > pq;
ll cnt, dap, mul,k=1000000LL;
int main(){
    int n;
    scanf("%d",&n);

    while(n--){
        ll a,b;
        scanf("%lld",&a);
        if(a==10){
            scanf("%lld",&b);
            pq.push(a+k);
            k -= b;
            //pq.emplace(a,b);
        }else if(a>0){
            pq.push(a+k);
        }else if(!pq.empty()){
            pq.pop();
        }
    }
    while(!pq.empty()){
        dap += pq.top()-k; pq.pop();
    }
    printf("%lld",dap);
}
