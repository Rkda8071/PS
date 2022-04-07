#include<bits/stdc++.h>
typedef long long ll;
ll a[1000001];

int main(){
    int t;
    scanf("%d",&t);
    for(ll i = 1LL; i<=1000000LL; i++){
        for(ll j = i; j<=1000000LL; j+=i)
            a[j] += i;
        a[i] += a[i-1];
    }
    while(t--){
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",a[n]);
    }
}