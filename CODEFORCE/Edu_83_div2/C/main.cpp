#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,k,a[40],chk[110];
bool f(){
    ll x;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt = 0;
        for(x=1;x<a[i];x*=k) ++cnt;
        while(a[i]){
            if(a[i]>=x){
                a[i] -= x;
                if(!chk[cnt]) chk[cnt] = 1;
                else return false;
            }
            x/=k; --cnt;
        }
    }
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&k);
        for(int i=0;i<=100;i++) chk[i] = 0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
