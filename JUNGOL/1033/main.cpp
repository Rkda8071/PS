#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
typedef pair<int,p> pp;
int n,sy,sx,ey,ex,k;
int a[51][51],d[51][51];
int yyy[4] = {0,0,1,-1}, xxx[4] = {1,-1,0,0};
//queue<int> q;
priority_queue<pp, vector<pp>, greater<pp> > pq;
void paint(int y,int x,int yy,int xx){
    if(y==yy){
        if(x>xx) swap(x,xx);
        for(int i=x;i<=xx;i++) a[y][i] = 1;
    } else{
        if(y>yy) swap(y,yy);
        for(int i=y;i<=yy;i++) a[i][x] = 1;
    }
}
int main(){
    scanf("%d",&n);
    scanf("%d %d %d %d",&sy,&sx,&ey,&ex);
    scanf("%d",&k);
    int m,ang,y,x,yy,xx;
    scanf("%d",&m);
    while(m--){
        scanf("%d %d %d",&ang,&yy,&xx);
        for(int i=1;i<ang;i++){
            scanf("%d %d",&y,&x);
            paint(y,x,yy,xx);
            yy = y; xx = x;
        }
    }
    //q.push(sy); q.push(sx);
    d[sy][sx] = a[sy][sx] ? k : 1;
    pq.push(make_pair(d[sy][sx],make_pair(sy,sx)));
    while(!pq.empty()){
        pp b = pq.top(); pq.pop();
        y = b.second.first;
        x = b.second.second;
        for(int i=0;i<4;i++){
            yy = y + yyy[i]; xx = x + xxx[i];
            if(yy>0 && yy<=n && xx>0 && xx<=n){
                if(d[yy][xx] == 0 || d[yy][xx] > d[y][x] + (a[yy][xx] ? k : 1)){
                    d[yy][xx] = d[y][x] + (a[yy][xx] ? k : 1);
                    pq.push(make_pair(d[yy][xx],make_pair(yy,xx)));
                    //q.push(yy); q.push(xx);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d ",d[i][j]);
        puts("");
    }
    printf("%d",d[ey][ex]);
    return 0;
}
