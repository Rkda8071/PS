#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l[210], s[210];
ll dp[200010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%lld %lld",&l[i], &s[i]);
    
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1] + 2000000000LL;
        for(int j=1;j<=m;j++){
            if(i < l[j])
                dp[i] = min(dp[i],s[j]);
            else
                dp[i] = min(dp[i],s[j] + dp[i-l[j]]);
        }
        printf("%lld\n",dp[i]);
    }
    return 0;
}