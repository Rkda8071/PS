#include<bits/stdc++.h>
using namespace std;
int a[320][21],d[320][21],chk[320][21];
void trace(int cnt,int x){
    if(x==0) return;
    trace(cnt-chk[cnt][x],x-1);
    printf("%d ",chk[cnt][x]);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%*d");
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    }
    for(int e=1;e<=m;e++){
        for(int k=1;k<=n;k++){
            for(int i=0;i<=k;i++){ // e회사에서 i만큼 투자
                if(d[k][e]<d[k-i][e-1]+a[i][e]){
                    d[k][e] = d[k-i][e-1]+a[i][e];
                    chk[k][e] = i;
                }
            }
        }
    }
    printf("%d\n",d[n][m]);
    trace(n,m);
    return 0;
}
