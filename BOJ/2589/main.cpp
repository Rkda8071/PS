#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
char a[51][51];
int n,m,cnt,chk[51][51];
int yyy[4] = {0,0,1,-1}, xxx[4] = {1,-1,0,0};
queue<tp> q;
int f(int y,int x){
    int maxim = 0,c;
    q.emplace(y,x,0); chk[y][x] = ++cnt;
    while(!q.empty()){
        tie(y,x,c) = q.front(); q.pop();
        maxim = max(maxim,c);
        for(int i=0;i<4;i++){
            int yy = y+yyy[i],xx = x+xxx[i];
            if(a[yy][xx] == 'L' && chk[yy][xx] != cnt){
                chk[yy][xx] = cnt;
                q.emplace(yy,xx,c+1);
            }
        }
    }
    return maxim;
}
int main(){
    int maxim=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j] == 'L')
                maxim = max(f(i,j),maxim);

    printf("%d",maxim);
    return 0;
}
