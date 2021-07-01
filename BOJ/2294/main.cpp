#include<bits/stdc++.h>
using namespace std;
int a[110];
int dp[11000];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)
        dp[i] = 2000000000;
    for(int i=0;i<n;i++){
        if(a[i]>k) continue;
        dp[a[i]] = 1;
        for(int j=a[i]+1;j<=k;j++){
            if(dp[j-a[i]]){
                dp[j] = min(dp[j-a[i]]+1,dp[j]);
            }
        }
    }
    //for(int i=1;i<=k;i++) printf("%d ",dp[i]);
    if(dp[k] == 2000000000) printf("-1");
    else printf("%d",dp[k]);
    return 0;
}
