#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll f(ll x){return x*(x+1)/2;}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&k);
        ll l=1,r=n;
        while(l<r){
            ll mid = (l+r)/2;
            if(f(mid) == k) break;
            else if(f(mid)<k) l = mid+1;
            else r = mid;
        }

        ll chk1 = (l+r)/2 + 1,chk2 = k - f((l+r)/2-1);
        for(ll i=n;i>=1;i--){
            if(i == chk1 || i==chk2) printf("b");
            else printf("a");
        }
        if(t) puts("");
    }
    return 0;
}
