#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll f(ll x){
    while(1){
        ll y=x,hap=0LL;
        while(y){
            hap+=y%10LL;
            y/=10LL;
        }
        ll a=x,b=hap;
        while(b){
            ll tmp = a%b;
            a = b;
            b = tmp;
        }
        if(a>1) break;
        x++;
    }
    return x;
}
int main(){
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",f(n));
    }
    return 0;
}
