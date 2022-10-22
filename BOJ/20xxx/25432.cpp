#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll a[10010],dp[10010][2][2],ans,mod = 10e9 + 7,mini = -(1<<62);
void init(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<=k;i++){
        dp[i][0][0] = dp[i][0][1] =
        dp[i][1][0] = dp[i][1][1] = mini;
    }
    dp[0][0][0] = dp[0][0][1] = 0;
}
void solve(){
    for(int i=1;i<=n;i++){
        // dp[쓴 각성제][i일에 안마심 0, i일에 마심 1]
        ll ai = a[i];
        int m = min(i,k);
        for(int j=0;j<m;j++){
            // 안먹어
            dp[j][0][i%2] = max(dp[j][1][(i+1)%2], dp[j][0][(i+1)%2]) + ai;
            //if(dp[j][0][i%2] > 0) dp[j][0][i%2] %= mod;
            //else dp[j][0][i%2] = max(mini, dp[j][0][i%2]);
            
            // 먹어
            ai *= 2;
            dp[j+1][1][i%2] = max(dp[j][1][(i+1)%2], dp[j][0][(i+1)%2]) + ai;
            //if(dp[j+1][1][i%2] > 0) dp[j+1][1][i%2] %= mod;
            //else dp[j+1][1][i%2] = max(mini, dp[j+1][1][i%2]);
        }
        dp[m][0][i%2] = max(dp[m][0][(i+1)%2],dp[m][1][(i+1)%2]) + ai;
        /*
        printf("\n\n%d\n",i);
        for(int j=0;j<=m;j++)
            printf("%d %lld %lld\n",j, dp[j][0][i%2], dp[j+1][1][i%2]);
        */
    }
    ans = mini;
    for(int i=0;i<=k;i++){
        ans = max({ans, dp[i][0][n%2], dp[i][1][n%2]});
    }
}
int main(){
    init();
    solve();
    if(ans>0) printf("%lld", ans%mod);
    else printf("%lld",ans);
}