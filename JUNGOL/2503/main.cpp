#include<bits/stdc++.h>
using namespace std;
struct A{
    set<int> s;
    int y,x,chk;
}a[10001];
int n,m,cnt;
int d[101][101],num[101][101];//,chk[10010];
int xxx[4] = {0,0,1,-1}, yyy[4] = {1,-1,0,0};
queue<tuple<int,int> > q;
set<int> :: iterator it;
void f(int y,int x){
    num[y][x] = ++cnt;
    a[cnt].y = y; a[cnt].x = x;
    q.emplace(y,x);
    while(!q.empty()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int yy = y+yyy[i],xx = x+xxx[i];
            if(yy>0 && yy<=n && xx>0 && xx<=m){
                if(d[yy][xx]==d[y][x] && !num[yy][xx]){
                    num[yy][xx] = num[y][x];
                    //q.push(yy); q.push(xx);
                    q.emplace(yy,xx);
                } else if(num[yy][xx] && d[yy][xx]!=d[y][x]){
                    a[num[y][x]].s.insert(num[yy][xx]);
                    a[num[yy][xx]].s.insert(num[y][x]);
                }
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&d[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(num[i][j] == 0)
                f(i,j);
    int c,ang,dap=2000000000,maxim = 0,chk2[10010]={0};
    for(int i=1;i<=cnt;i++){
        if(chk2[i]) continue;
        int chk[10010] = {0};
        chk[i] = 1;
        q.emplace(i,0);
        maxim = 0;
        while(!q.empty()){
            tie(c,ang) = q.front(); q.pop();
            maxim = max(maxim,ang);
            for(it = a[c].s.begin();it!=a[c].s.end();it++){
                if(!chk[*it]){
                    chk[*it] = chk[c]+1;
                    q.emplace(*it,ang+1);
                }
            }
        }
        dap = min(dap,maxim);
        for(int j=i+1;j<=cnt;j++){
            if(maxim-(chk[j]-1)>=dap) chk2[j] = 1;
        }
    }
    printf("%d",dap);
    return 0;
}
