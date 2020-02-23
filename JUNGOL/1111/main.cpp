#include<bits/stdc++.h>
using namespace std;
int n;
int ey,ex;
int a[110][110],d[110][110];
int yyy[4] = {0,0,1,-1},xxx[4] = {1,-1,0,0};
queue<tuple<int,int>> q;
void in(){
    scanf("%d %d %d",&n,&ey,&ex);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++) d[i][j] = 2000000000;
}
int p(int x,int y){
    if(x==y) return 0;
    if(x>y) return x-y;
    return (y-x)*(y-x);
}
void f(){
    d[0][0] = 0;
    q.emplace(0,0);
    while(!q.empty()){
        int y,x;
        tie(y,x) = q.front(); q.pop();
        if(y==ey && x==ex) continue;
        for(int i=0;i<4;i++){
            int yy = y+yyy[i],xx = x+xxx[i];
            if(yy>=0 && yy<=n+1 && xx>=0 && xx<=n+1){
                if(d[yy][xx]>d[y][x] + p(a[y][x],a[yy][xx])){
                    d[yy][xx] = d[y][x] + p(a[y][x],a[yy][xx]);
                    q.emplace(yy,xx);
                }
            }
        }
    }
}
int main(){
    in();
    f();
    printf("%d",d[ey][ex]);
    return 0;
}
