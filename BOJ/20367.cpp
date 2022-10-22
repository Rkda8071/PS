#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[3010];
ll dp[3010][3010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    
    for(int i=3;i<=n;i+=2){
        for(int j=1;j<=i-2;j++){
            //j, i-1, i
            dp[i][j] = max(dp[i][j], dp[i-2][j] + a[i]*a[i-1]);
            dp[i][i-1] = max(dp[i][i-1], dp[i-2][j] + a[j]*a[i]);
            dp[i][i] = max(dp[i][i], dp[i-2][j] + a[j]*a[i-1]);
        }
    }
    ll answer = 0LL;
    if(n%2)
        for(int i=1;i<=n;i++)
            answer = max(answer, dp[n][i]);
    else
        for(int i=1;i<=n;i++)
            answer = max(answer, dp[n-1][i]+ a[i]*a[n]);
    printf("%lld",answer);
    return 0;
}