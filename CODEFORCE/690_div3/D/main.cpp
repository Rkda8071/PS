#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[3010],d[3010];
bool f(ll nn){
    if(d[n]%nn) return false;
    ll ang = d[n]/nn,chk = 1LL,cur; //같은 값
    if(ang*n < d[n]) return false;
    cur = ang;
    while(--nn){
        for(;chk<=n;chk++){
            if(d[chk] == cur){
                cur+=ang;
                break;
            }else if(d[chk]>cur){
                return false;
            }
        }
    }
    if(d[n] != cur) return false;
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) d[i] = d[i-1]+a[i];
        for(ll nn=n;nn>=1LL;nn--){ // nn은 횟수
            if(f(nn)){
                printf("%lld\n",n-nn);
                break;
            }
        }
    }
}
