#include<bits/stdc++.h>
using namespace std;
int d[10010],t[10010],tt[10010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    // d[n] = d[n-1] + d[n-2] + t[n-1]*2 + tt[n-1];
    // t[n] = d[n-2] + d[n-1] + t[n-1];
    //tt[n] = d[n-1] + tt[n-2];
    d[0] = d[1] = t[1] = tt[1] = 1;
    //d[2] = 5; t[2] = 2; tt[2] = 2;
    for(int i=2;i<=n;i++){
        d[i] = d[i-1] + d[i-2] + t[i-1]*2 + tt[i-1];
        t[i] = t[i-1] + d[i-1];
        tt[i] = d[i-1] + tt[i-2];
        d[i] %= m; t[i] %= m; tt[i] %= m;
    }
    printf("%d",d[n]);
    return 0;
}
