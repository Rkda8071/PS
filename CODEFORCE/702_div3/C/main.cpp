#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x;
ll a[10010];
bool f(){
    for(ll i=1LL;i<=10000LL;i++){
        ll ang = x-i*i*i;
        if(ang<=0LL) break;
        int x = lower_bound(a+1,a+10001,ang) - a;
        if(ang == a[x]) return true;
    }
    return false;
}
int t;
int main(){
    for(ll i=1LL;i<=10000LL;i++)
        a[i] = i*i*i;

    scanf("%d",&t);
    while(t--){
        scanf("%lld",&x);
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
