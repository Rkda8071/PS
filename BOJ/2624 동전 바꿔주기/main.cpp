#include<bits/stdc++.h>
using namespace std;
int a[101],b[101];
int dp[101][10010];
int main(){
    int t,n,cnt=0;
    bool chk;
    scanf("%d %d",&t,&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=t;j++){
            if(dp[i-1][j]>0){
                for(int l=0;l<=b[i];l++){
                    if(j+a[i]*l>t) break;
                    dp[i][j+a[i]*l]+=dp[i-1][j];
                }
            }
        }
    }
    printf("%d",dp[n][t]);
    return 0;
}
