#include<bits/stdc++.h>
#define mod 1000000009L
using namespace std;
typedef long long ll;
ll d[1000010];
int main(){
    ll n,k;
    scanf("%lld %lld",&n,&k);
    d[0] = 1;
    for(int i=0;i<4;i++) d[i+1] = d[i]*k;
    for(int i=5;i<=n;i++){
        d[i] = (d[i-1]*k - 2*d[i-5] + ((i>=7) ? d[i-7] : 0L) + 5*mod)%mod;
    }
    printf("%lld",d[n]);
    return 0;
}

/*ll d[1001000][6];
int main(){
    ll n,k;
    scanf("%lld %lld",&n,&k);
    d[1][0] = k-1; d[1][1] = 1;
    for(int i=1;i<n;i++){
        d[i+1][0] = ((d[i][0]+d[i][1]+d[i][2]+d[i][3]+d[i][4])*(k-2)+d[i][0])%mod;
        d[i+1][1] = (d[i][0]+d[i][1]+d[i][2]+d[i][3]+d[i][4])%mod;
        d[i+1][2] = d[i][1]%mod;
        if(i>=3) d[i+1][3] = (d[i][2] - d[i-2][2]+mod)%mod;
        else d[i+1][3] = d[i][2]%mod;
        d[i+1][4] = d[i][3]%mod;
    }
    printf("%lld",(d[n][0]+d[n][1]+d[n][2]+d[n][3]+d[n][4])%mod);
    return 0;
}*/
