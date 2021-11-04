#include<bits/stdc++.h>
#define mod 1000000
using namespace std;
int t=10,n,h;
int a[1010],d[1010],dp[1010][10001];
int main(){
    while(t--){
        scanf("%d %d",&n,&h);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=2;i<=n;i++)
            scanf("%d",&d[i]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=h;j++)
                dp[i][j] = 0 ;

        dp[0][0] = dp[1][a[1]] = 1;
        for(int i=2;i<=n;i++){
            for(int j=a[i]-d[i];j<=h;j++){
                dp[i][j] = (dp[i][j] + dp[i-1][j-(a[i]-d[i])]) % mod;
            }
            for(int j=a[i];j<=h;j++){
                dp[i][j] = (dp[i][j] + dp[0][j-a[i]]) % mod;
            }
            for(int j=0;j<=h;j++){
                dp[0][j] = (dp[0][j] + dp[i-1][j]) % mod;
            }
        }
        int hap = 0;
        for(int i=1;i<=h;i++)
            hap = (hap + dp[0][i] + dp[n][i]) % mod;

        printf("#%d %d",10-t,hap);
    }
}
/*
10 100
49 64 69 76 45 40 50 36 57 87
18 13 58 30 30 31 26 32 50


*/
