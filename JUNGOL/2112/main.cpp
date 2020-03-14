#include<bits/stdc++.h>
using namespace std;
int d[30][4],n;
void solve(){
    if(n%2) return;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            d[i][j] = max(d[i-2][j],)
        }
    }
}
int main(){
    scanf("%d",&n);
    solve();
    printf("%d",d[n][3]);
    return 0;
}
