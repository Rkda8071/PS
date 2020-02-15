#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,y;
priority_queue<ll,vector<ll>,greater<ll> >pq;
void g(ll m,ll x){
    if(x>n) return;

    if(x<n/2 && n%m == (x*2)%m){
        for(ll i=0;i<=9;i++){
            g(m*10,m*i+x);
        }
    }else{
        ll dap = (n-x)/(m/10);
        while(dap){
            if(11>dap) return;
            x += (dap%10)*m;
            dap -= (dap%10)*11;
            dap/=10; m*=10;
        }
        pq.push(x);
    }
}
int main(){
    scanf("%lld",&n);
    for(ll i=0;i<=9;i++){
        g(10,i);
    }
    printf("%d\n",pq.size());
    while(!pq.empty()){
        ll x = pq.top(); pq.pop();
        int nn = 0;
        for(ll i=x;i>0;i/=10) nn++;
        nn--;
        printf("%lld + %0*lld = %lld\n",x,nn,n-x,n);
    }
    return 0;
}
