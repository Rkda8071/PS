#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[30],b[30],chk[30];
ll n,ang,cnt[30];
ll f(ll x){
    ll ang = 1;
    while(x){
        ang *= x;
        --x;
    }
    return ang;
}

int main(){
    scanf("%lld",&n);
    scanf(" %s %s",a+1,b+1);

    ll A = 0L, B = 0L;

    A += (a[1] - 97L) * f(n-1);
    for(int i=2;i<=n;i++){
        ang = 0L;
        for(int j=1;j<i;j++) if(a[j]<a[i]) ang++;
        cnt[i] = (ll)(a[i]-'a'-ang);
    }
    ang = 0L;
    for(ll i=2;i<=n;i++)
        ang += f(n-i) * cnt[i];
    A += ang;

    B += (b[1] - 97L) * f(n-1);
    for(int i=2;i<=n;i++){
        ang = 0L;
        for(int j=1;j<i;j++) if(b[j]<b[i]) ang++;
        cnt[i] = (ll)(b[i]-'a'-ang);
    }
    ang = 0L;
    for(ll i=2;i<=n;i++)
        ang += f(n-i) * cnt[i];
    B += ang;
    printf("%lld",abs(A-B));
    //printf("%lld %lld",A,B);
    return 0;
}
