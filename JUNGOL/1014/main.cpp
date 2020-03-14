#include<bits/stdc++.h>
#define rsw (sw+1)%2
using namespace std;
int n,m;
char t[50],a[3][110];
long long d[2][3][110];
void init(){
    scanf("%s %s %s",t+1,a[1]+1,a[2]+1);
    for(n=1;t[n+1]!=NULL;n++);
    for(m=1;a[1][m+1]!=NULL;m++);
    for(int j=1;j<=m;j++){
        d[1][1][j] = d[1][1][j-1]; d[1][2][j] = d[1][2][j-1];
        if(a[1][j] == t[1]) d[1][1][j]++;
        if(a[2][j] == t[1]) d[1][2][j]++;
    }
}
int main(){
    init();
    int sw = 1;
    for(int i=2;i<=n;i++){
        sw = rsw;
        for(int j=1;j<=m;j++){
            d[sw][1][j] = d[sw][1][j-1]; d[sw][2][j] = d[sw][2][j-1];
            if(a[1][j] == t[i])
                d[sw][1][j] += d[rsw][2][j-1];
            if(a[2][j] == t[i])
                d[sw][2][j] += d[rsw][1][j-1];
        }
    }
    printf("%lld",d[sw][1][m]+d[sw][2][m]);
    return 0;
}
