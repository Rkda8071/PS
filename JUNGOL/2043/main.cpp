#include<bits/stdc++.h>
#define mod 10000
using namespace std;

int n;
int a[30][30];
int d[1<<21];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    d[0] = 1;
    for(int x=1;x<(1<<n);x++){
        int cnt = __builtin_popcount(x);
        for(int i=0;i<n;i++){
            if((x&(1<<i))){
                int ang = x^(1<<i);
                d[x] = (d[x] + d[ang] * a[cnt][i])%mod;
            }
        }
    }
    printf("%d",d[(1<<n)-1]);
    return 0;
}
