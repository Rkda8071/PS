#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
priority_queue<tp,vector<tp>,greater<tp> > pq;
int n,m,h;
int a[1010][1010],b[1010][1010],chk[1010][1010];
void init(){
    scanf("%d %d %d",&n,&m,&h);
    for(int i=0;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]); // À§¾Æ·¡
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++) scanf("%d",&b[i][j]); // ÁÂ¿ì
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) chk[i][j] = h;
}
void f(int y,int x){
    if(y>1 && a[y-1][x]!=-1) pq.emplace(max(chk[y][x],a[y-1][x]),y-1,x);
    if(y<n && a[y][x]!=-1) pq.emplace(max(chk[y][x],a[y][x]),y+1,x);
    if(x>1 && b[y][x-1]!=-1) pq.emplace(max(chk[y][x],b[y][x-1]),y,x-1);
    if(x<m && b[y][x]!=-1) pq.emplace(max(chk[y][x],b[y][x]),y,x+1);
}
int main(){
    init();
    for(int i=1;i<=m;i++){
        if(a[0][i]!=-1) pq.emplace(a[0][i],1,i);
        if(a[n][i]!=-1) pq.emplace(a[n][i],n,i);
    }
    for(int i=1;i<=n;i++){
        if(b[i][0]!=-1) pq.emplace(b[i][0],i,1);
        if(b[i][m]!=-1) pq.emplace(b[i][m],i,m);
    }
    int z,y,x;
    while(!pq.empty()){
        tie(z,y,x) = pq.top(); pq.pop();
        if(chk[y][x]!=h) continue;
        chk[y][x] = z;
        f(y,x);
    }
    int hap = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) hap+=chk[i][j];
    printf("%d",hap);
    return 0;
}
