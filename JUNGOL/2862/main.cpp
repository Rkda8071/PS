#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[101][10001];
int main(){
    scanf("%d %d",&n,&m);
    if(m>n) swap(n,m);
    for(int i=1;i<=n;i++) d[1][i] = i;
    for(int i=2;i<=m;i++){ // i는 높이, j는 가로
        int ang = min(i*3,n+1);
        d[i][i] = 1;
        for(int j=i+1;j<ang;j++){

            d[i][j] = 2000000000;
            for(int k=1;k<=i/2;k++)
                d[i][j] = min(d[i][j], d[k][j] + d[i-k][j]);
            for(int k=1;k<=j/2;k++)
                d[i][j] = min(d[i][j], d[min(i,k)][max(i,k)]
                                        + d[min(i,j-k)][max(i,j-k)]);
        }
        for(int j=ang;j<=n;j++)
            d[i][j] = d[i][j-i] + 1;
    }
    printf("%d",d[m][n]);
    return 0;
}
