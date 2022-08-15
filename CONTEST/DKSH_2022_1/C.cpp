#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[100010][4];
char a[100010];
int main(){
    scanf("%d %s",&n,a+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++) dp[i][j] = dp[i-1][j];
        if(a[i] == 'D') dp[i][0]++;
        if(a[i] == 'K') dp[i][1]+=dp[i-1][0];
        if(a[i] == 'S') dp[i][2]+=dp[i-1][1];
        if(a[i] == 'H') dp[i][3]+=dp[i-1][2];
    }

    printf("%lld",dp[n][3]);
}