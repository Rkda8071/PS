#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,a[100010],b,n;
int main(){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld %lld",&a[i],&b);
        ans += b;
    }
    sort(a+1,a+n+1);
    for(ll i=n;i>=1;i--)
        ans += a[i]*i;
    printf("%lld",ans);
}