#include<bits/stdc++.h>
using namespace std;
int n, a[2010],maxim = 1,dp[2010][2010];
int f(int x,int gap){
    int y = lower_bound(a+x+1,a+n,a[x] + gap) - a;
    if(y >= n || a[y] != a[x] + gap) return 0;
    if(dp[x][y]) return dp[x][y];
    return dp[x][y] = f(y, gap) + 1;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n;j++){
            if(dp[i][j]) continue;
            dp[i][j] = f(j, a[j] - a[i]) + 2;
            maxim = max(dp[i][j], maxim);
        }
    }
    printf("%d",maxim);
    return 0;
}
