#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll d[100100][9];
int path[10][10]={
    {0},{2,8,0,0},{1,3,8,0},{2,4,7,8},{3,5,7,0},{4,6,0,0},{5,7,0,0},{3,4,6,8},{1,2,3,7}
};
int main(){
    d[0][1] = 1L;
    int dis;
    scanf("%d",&dis);
    for(int i=1;i<=dis;i++){
        for(int j=1;j<=8;j++){
            for(int l=0;l<4;l++){
                d[i][j] = (d[i][j] + d[i-1][path[j][l]]) % mod;
            }
        }
    }
    printf("%lld",d[dis][1]);
    return 0;
}
