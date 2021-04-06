#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
ll a[10000];
int main(){
    ll n,m,dap = 1;
    ll ang = 2;
    scanf("%lld %lld",&n,&m);
    for(ll i=0;i<(n+1)/2;i++){
        a[j] *= (m-i);
        for(int j=1;j<=10000;j++)
            a[j+1] += a[j]%10000000000;
    }//////////////////////////sibal
    for(ll i=2;i<=(n+1)/2;i++){
        dap = dap/i;
    }
    printf("%lld",dap);
}
