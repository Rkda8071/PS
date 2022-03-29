#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int d[110][110],yyy[4] = {0,0,1,-1},xxx[4] = {1,-1,0,0};
char a[110][110];
int main(){
    int n,m;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    q.push(1); q.push(1);
    d[1][1] = 1;
    while(!q.empty()){
        int y = q.front(); q.pop();
        int x = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int yy = y+yyy[i], xx = x+xxx[i];
            if(yy>=1 && yy<=n && xx>=1 && xx<=m){
                if(a[yy][xx] == '0'){
                    if(d[yy][xx] == 0 || d[yy][xx]>d[y][x]){
                        d[yy][xx] = d[y][x];
                        q.push(yy); q.push(xx);
                    }
                } else{
                    if(d[yy][xx] == 0 || d[yy][xx]>d[y][x]+1){
                        d[yy][xx] = d[y][x] + 1;
                        q.push(yy); q.push(xx);
                    }
                }
            }
        }
    }
    printf("%d",d[n][m]-1);
    return 0;
}
