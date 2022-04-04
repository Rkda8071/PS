#include<bits/stdc++.h>
using namespace std;
int a[101],chk[101],d[30][110];
int n,m;
void f(int c,int x){
    d[c][x] = min(d[c][x],d[c+3][x-1]); // ÄíÆù »ç¿ë
    d[c][x] = min(d[c][x],d[c][x-1]+10);
    if(x>=3) d[c+1][x] = min(d[c+1][x],d[c][x-3]+25);
    if(x>=5) d[c+2][x] = min(d[c+2][x],d[c][x-5]+37);
}
void init(){
    for(int i=1;i<=n;i++) a[i] = 1;
    for(int i=0;i<m;i++) a[chk[i]] = 0;
    for(int i=0;i<=26;i++)
        for(int j=0;j<=n;j++) d[i][j] = 2000000000;
    d[0][0] = 0;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d",&chk[i]);
    init();
    for(int i=1;i<=n;i++){
        //if(a[i])
            for(int j=22;j>=0;j--) f(j,i);
        if(!a[i])//else
            for(int j=22;j>=0;j--)
                d[j][i] = min(d[j][i],d[j][i-1]);
    }
    int mini = 2000000000;
    for(int i=0;i<=22;i++) mini = min(mini,d[i][n]);
    if(mini == 0) printf("0");
    else printf("%d000",mini);
    return 0;
}
