#include<bits/stdc++.h>
using namespace std;
int n;
int a[26][26];
int d[26][26][26][26];
int yyy[9] = {0,1,1,0,-1,-1,-1,0,1},xxx[9] = {0,0,1,1,1,0,-1,-1,-1};
int sy,sx,ey,ex;
int ssy,ssx,eey,eex;
queue<tuple<int,int,int,int>> q;
int main(){
    int y,x,yy,xx;
    scanf("%d",&n);
    scanf("%d %d %d %d",&sy,&sx,&ey,&ex);
    scanf("%d %d %d %d",&ssy,&ssx,&eey,&eex);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    d[sy][sx][ssy][ssx] = 1;
    q.emplace(sy,sx,ssy,ssx);
    while(!q.empty()){
        tie(y,x,yy,xx) = q.front();
        q.pop();
        if(y==ey && x==ex && yy==eey && xx==eex){
            printf("%d",d[y][x][yy][xx]-1);
            break;
        }
        for(int i=0;i<9;i++){
            int ny = y+yyy[i],nx = x+xxx[i];

            if(ny>0 && ny<=n && nx>0 && nx<=n && a[ny][nx]==0){
                for(int j=0;j<9;j++){
                    int nny = yy+yyy[j],nnx = xx+xxx[j];
                    if(abs(nny-ny)<=1 && abs(nnx-nx)<=1) continue;
                    if(nny>0 && nny<=n && nnx>0 && nnx<=n && a[nny][nnx]==0){
                        if(d[ny][nx][nny][nnx]==0 || d[ny][nx][nny][nnx]>d[y][x][yy][xx]+1){
                            q.emplace(ny,nx,nny,nnx);
                            d[ny][nx][nny][nnx] = d[y][x][yy][xx] + 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
