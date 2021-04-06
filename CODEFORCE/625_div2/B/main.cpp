#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 10000000000000000L;
int a[200100];
ll b[600100],b2[600100];
int main(){
    int n;
    ll m = 0,m2 = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        int x = a[i]-i+200000;
        b[x] += (ll)a[i];
        b2[x] += b[x]/mod; b[x] = b[x]%mod;
        if(m2<b2[x] || (m2==b2[x] && m<b[x])){
            m2 = b2[x];
            m = b[x];
        }
    }
    if(m2>0) printf("%lld%016lld",m2,m);
    else printf("%lld",m);
    return 0;
}
