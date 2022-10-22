#include<bits/stdc++.h>
using namespace std;
int n,sx,sy,k;
int yyy[8] = {2,1,-1,-2,-2,-1,1,2}, xxx[8] = {1,2,2,1,-1,-2,-2,-1};
long double dp[51][51][51];
int main(){
    scanf("%d %d %d %d",&n,&sx,&sy,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            dp[0][i][j] = 1.0;
    }
    for(int kk=1; kk<=k; kk++){
        for(int y=1;y<=n;y++){
            for(int x=1;x<=n;x++){
                for(int i=0;i<8;i++){
                    int yy = y+yyy[i], xx = x+xxx[i];
                    if(yy>0 && yy<=n && xx>0 && xx<=n)
                        dp[k][y][x] += dp[kk-1][yy][xx];
                }
                dp[k][y][x]/=8.0;
            }
        }
    }
    printf("%.20lf",dp[k][sy][sx]);
    return 0;
}