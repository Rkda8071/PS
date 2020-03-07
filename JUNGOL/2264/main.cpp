#include<bits/stdc++.h>
#define mod 1000000003
using namespace std;
int d[1010][1010],dap,n,k;
int main(){
    /*scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) d[i][1] = 1;
    for(int i=3;i<n;i++)
        for(int j=1;j<i-1;j++)
            for(int l=1;l<k;l++)
                d[i][l+1] = (d[i][l+1]+d[j][l])%mod;

    for(int i=1;i<n;i++)
        dap = (dap+d[i][k])%mod;
    dap = (dap+d[n-1][k])%mod;

    printf("%d",dap);*/
    scanf("%d %d",&n,&k);
    //i개 중에서 j개 선택하는 경우
    //d[1][1] = 1;
    for(int i=1;i<=n;i++) d[i][1] = i;
    for(int i=1;i<=n;i++) d[i][0] = 1;
    for(int i=3;i<=n;i++){
        for(int j=2;j<=k;j++){
            d[i][j] = (d[i-1][j] + d[i-2][j-1])%mod;
        }
    }
    printf("%d",(d[n-1][k]+d[n-3][k-1])%mod);
    return 0;
}
