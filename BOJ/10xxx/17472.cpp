#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tp;
priority_queue<tp, vector<tp>, greater<tp> > pq;
int n,m,num = 2;
int a[11][11],p[11];
int yyy[4] = {0,0,1,-1}, xxx[4] = {1,-1,0,0};
int fin(int x){
    if(p[x] == x) return x;
    return p[x] = fin(p[x]);
}
void uni(int y,int x){
    p[fin(y)] = fin(x);
}
void dfs(int y,int x){
    a[y][x] = num;
    for(int i=0;i<4;i++){
        int yy = y+yyy[i], xx = x+xxx[i];
        if(yy>0 && yy<=n && xx>0 && xx <= m && a[yy][xx] == 1)
            dfs(yy,xx);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 1){
                dfs(i,j);
                num++;
            }
        }
    }
    for(int i=2;i<num;i++) p[i] = i;

    for(int y=1;y<=n;y++){
        int s=0,d=0;
        for(int x=1;x<=m;x++){
            if(a[y][x]){
                if(a[y][x] == s) {d = 0; continue;}
                if(s == 0) s = a[y][x];
                else{
                    if(d>1) pq.push(tp(d,s,a[y][x]));
                    s = a[y][x]; d = 0;
                }
            }else if(s) d++;
        }
    }
    for(int x=1;x<=m;x++){
        int s=0,d=0;
        for(int y=1;y<=n;y++){
            if(a[y][x]){
                if(a[y][x] == s) {d = 0; continue;}
                if(s == 0) s = a[y][x];
                else{
                    if(d>1) pq.push(tp(d,s,a[y][x]));
                    s = a[y][x]; d = 0;
                }
            }else if(s) d++;
        }
    }
    int ans = 0, cnt = 0;
    while(!pq.empty()){
        int d,s,e;
        tie(d,s,e) = pq.top(); pq.pop();
        if(fin(s) == fin(e)) continue;
        ans += d; ++cnt;
        uni(s,e);
    }
    if(cnt == num-3)
        printf("%d",ans);
    else printf("-1");
    return 0;
}