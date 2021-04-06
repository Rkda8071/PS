#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010];
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        ll dap = 0LL,n;
        set<ll> s;
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(ll i=1;i<=n;i++) if(a[i]>1LL) s.insert(i);
        for(ll i=1;i<=n;i++){
            if(a[i]>n){
                dap+=a[i]-n;
                a[i] = n;
            }
            while(a[i]>1LL){
                ll j = i+a[i];
                while(j<=n){
                    auto it = s.lower_bound(j);
                    if(it == s.end()) break;
                    int x = *it;
                    j = x+a[x];
                    a[x] = max(1LL,a[x]-1LL);
                    if(a[x] == 1LL) s.erase(*it);
                }
                a[i]--;
                dap++;
            }
            /*while(a[i]>1LL){
                for(ll j=i+a[i];j<=n;){
                    int x = j+a[j];
                    a[j] = max(1LL,a[j]-1LL);
                    j = x;
                }
                a[i]--;
                dap++;
            }*/
            if(s.find(i)!=s.end()) s.erase(i);
        }
        printf("%lld\n",dap);
    }
    return 0;
}
