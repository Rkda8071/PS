#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
typedef pair<int,p> pp;
vector<p> trace;
int n,sy,sx,ey,ex,k,cnt;
int a[51][51],d[51][51],path[51][51];
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
                    path[yy][xx] = i;
                    pq.push(make_pair(d[yy][xx],make_pair(yy,xx)));
                    //q.push(yy); q.push(xx);
                }
            }
        }
    }
    printf("%d\n",d[ey][ex]);
    y = ey; x = ex; trace.push_back(make_pair(y,x));
    while(y!=sy || x!=sx){
        yy = y; xx = x;
        y -= yyy[path[yy][xx]]; x-=xxx[path[yy][xx]];
        if(y==sy && x==sx) break;
        if(path[yy][xx]/2 != path[y][x]/2) trace.push_back(make_pair(y,x));
    }
    trace.push_back(make_pair(y,x));
    printf("%d ",trace.size());
    for(int i=trace.size()-1;i>=0;i--) printf("%d %d ",trace[i].first,trace[i].second);
    return 0;
}
