#include<bits/stdc++.h>
using namespace std;
int a[100100],dp[1<<8][100100];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        a[x] = 1; // 수업 안하는 날!!
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<8);j++)
            d[i][j] = 2000000000;
        for(int j=0;j<(1<<8);j++){
            for(int l=0;l<8;++){ // 쿠폰 쓰는 경우
                if(i==l) break;
                if(!(j&(1<<l))){ // l+1일짜리 쿠폰을 안썼음
                    d[i][j|(1<<l)] = min(d[i][j|(1<<l)],d[i-(l+1)][j]);
                }
            }
            d[i][j] = min(d[i][j],d[i-1][j]+(a[i]) ? 0:9); // 수업 아니면 0원
            if(i>=4) d[i][j] = min(d[i][j],d[i-4][j]+30);
            if(i>=8) d[i][j] = min(d[i][j],d[i-8][j]+48);
        }
    }
    int ans = 2000000000;
    for(int i=0;i<(1<<8);i++)
        ans = min(ans,d[n][i]);
    if(ans == 0) printf("0");
    else printf("%d0000",ans);
}
