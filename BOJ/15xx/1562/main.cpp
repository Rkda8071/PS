#include<bits/stdc++.h>
#define m 1000000000
using namespace std;
int d[120][10][1<<10];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=9;i++) d[1][i][1<<i] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=8;j++){
            for(int k=1;k<1024;k++){
                d[i][j][k|(1<<j)] += d[i-1][j-1][k];
                d[i][j][k|(1<<j)] += d[i-1][j+1][k];
                d[i][j][k|(1<<j)] = d[i][j][k|(1<<j)] % m;
            }
        }
        for(int k=1;k<1024;k++){
            d[i][9][k|(1<<9)] += d[i-1][8][k];
            d[i][9][k|(1<<9)] = d[i][9][k|(1<<9)] % m;
            d[i][0][k|(1<<0)] += d[i-1][1][k];
            d[i][0][k|(1<<0)] = d[i][0][k|(1<<0)] % m;
        }
    }
    int dap = 0;
    for(int i=0;i<=9;i++){
        dap += d[n][i][1023];
        dap = dap % 1000000000;
    }
    printf("%d",dap);
}
