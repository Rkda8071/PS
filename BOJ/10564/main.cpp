#include<bits/stdc++.h>
using namespace std;
int s[11], d[5010][510];
int n,m;
int solve(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=500;j++)
            d[i][j] = -1;
    d[0][0] = 0;
    for(int i=1;i<=m;i++) scanf("%d",&s[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<=500;j++){
            if(d[i][j] == -1) continue;
            for(int l=1;l<=m;l++){
                if(i+j+s[l] > n) continue;
                d[i+j+s[l]][j+s[l]] = 1;
            }
        }
    }
    for(int i=500;i>=0;i--)
        if(d[n][i]>0) return i;
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
        printf("%d\n", solve());
    return 0;
}

