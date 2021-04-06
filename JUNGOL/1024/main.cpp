#include<bits/stdc++.h>
using namespace std;
int a[510][510],d[510][510];
int cnt[510][510];
int yyy[4] = {0,1,0,-1}, xxx[4] = {1,0,-1,0};
queue<tuple<int,int> > q;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);

    q.emplace(1,1);
    while(!q.empty()){
        int y,x;
        tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int yy = y + yyy[i],xx = x + xxx[i];
            if(yy>0 && yy<=n && xx>0 && xx<=m && a[yy][xx]<a[y][x])
                if(!cnt[yy][xx]++)
                    q.emplace(yy,xx);
        }
    }

    d[1][1] = 1;
    q.emplace(1,1);
    while(!q.empty()){
        int y,x;
        tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int yy = y + yyy[i],xx = x + xxx[i];
            if(yy>0 && yy<=n && xx>0 && xx<=m && a[yy][xx]<a[y][x])
                d[yy][xx] += d[y][x];
                if(--cnt[yy][xx] == 0)
                    q.emplace(yy,xx);
        }
    }
    printf("%d",d[n][m]);
    return 0;
}
