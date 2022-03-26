#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
ll cnt[100010],maxim,hap;
int main(){
    scanf("%lld %lld",&n,&q);
    while(q--){
        ll x,y,z;
        scanf("%lld %lld %lld",&x,&y,&z);
        if(x==1LL){ // y개의 표가 z후보에게
            cnt[z] += y;
            if(z!=n+1){
                maxim = max(maxim, cnt[z]);
                hap += y;
            }
        }else{
            if(cnt[n+1] + y > max(maxim, (hap+z)/n + ((hap+z)%n ? 1LL : 0LL))) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
