#include<bits/stdc++.h>
#define MIN -400000000000000LL;
using namespace std;
typedef long long ll;
int n,chk[200010];
ll a[200010], dp[200010][3], ans = MIN;

vector<int> v[200010];

void dfs(int x){
    ll sum = 0LL, m1, m2, ang;
    dp[x][0] = dp[x][1] = dp[x][2] = m1 = m2 = MIN;
    for(int y : v[x]){
        dfs(y);
        ang = max(dp[y][2], max(dp[y][0], dp[y][1]));
        if(dp[y][1]<=0) {
            //if(dp[x][2]<ang) dp[x][2] = ang;
            dp[x][2] = max(dp[x][2],ang);
        }
        else{
            sum += dp[y][1];
            dp[x][2] = max(dp[x][2],dp[y][2]);
        }

        if(m1<ang){
            m2 = m1;
            m1 = ang;
        }
        else if(m2<ang) m2 = ang;

        dp[x][0] = max(dp[x][0], ang);
    }
    dp[x][1] = sum + a[x];
    ans = max(ans, max(dp[x][1]+dp[x][2], m1+m2));
}
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%lld %d",&a[i],&x);
        if(x != -1) v[x].push_back(i);
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}