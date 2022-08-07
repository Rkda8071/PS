#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,kk,cnt;
ll a, ang[20],chk[10];
ll f(ll x, int m){
    ll tmp=0LL;
    if(x/ang[m+1] < a/ang[m+1]) return 0LL;
    if(m+1 < k) return 0LL;
    if(x>a || m==-1){
        for(ll j=(ll)k-1;j>=0;j--){
            ll mini = -1;
            for(ll i=0; i<10; i++){
                if(!chk[i]){
                    chk[i] = 1;
                    mini = i;
                    break;
                }
            }
            x += mini*ang[j];
        }
        ll mini = -1;
        for(ll i=0; i<10; i++){
            if(chk[i]){
                mini = i;
                break;
            }
        }
        while(m>=k){
            x += mini*ang[m--]; 
        }
        return x;
    }
    for(ll i=0;i<10;i++){
        if(!chk[i]){
            if(k){
                --k; chk[i] = 1;
                tmp = f(x + i*ang[m], m-1);
                ++k; chk[i] = 0;
            }
        }else{
            tmp = f(x + i*ang[m], m-1);
        }
        if(tmp) return tmp;
    }
    return 0LL;
}
int main(){
    ll m,tmp;
    scanf("%lld %d",&a,&k);
    ang[0] = 1LL;
    for(int i=1; i<=19;i++) ang[i] = ang[i-1] * 10LL;
    for(m=0,tmp=a; tmp; m++) tmp/=10;
    if(m >= k){
        ll ans = 0LL;
        ans = f(0LL, m-1);
        chk[1] = 1; k--;
        if(ans == 0LL) ans = f(ang[m], m-1);
        printf("%lld",ans);
    }
    else{
        printf("10");
        for(int i=2;i<k;i++)
            printf("%d",i);
    }
    return 0;
}