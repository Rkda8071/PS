#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f(ll x){
    int ang = 0;
    while(x){
        ang += x%2LL;
        x/=2LL;
    }
    return ang!=1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        //printf("[%d]",__builtin_popcount(n));
        if(f(n)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
