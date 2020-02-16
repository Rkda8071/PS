#include<bits/stdc++.h>
using namespace std;
int xxx[6] = {1,-1,0,0,0,0},yyy[6] = {0,0,1,-1,0,0},zzz[6] = {0,0,0,0,1,-1};
int a[110][110][110];
queue<int> q;

int main(){
    int m,n,h;
    int x,y,z;
    scanf("%d %d %d",&m,&n,&h);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                scanf("%d",&a[i][j][l]);
                if(a[i][j][l] == 1){q.push(i); q.push(j); q.push(l);}
            }
        }
    }
    while(!q.empty()){
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        z = q.front(); q.pop();
        for(int i=0;i<6;i++){
            int xx = x+xxx[i],yy = y+yyy[i],zz = z+zzz[i];
            if(xx>0 && xx<=h && yy>0 && yy<=n && zz>0 && zz<=m){
                if(a[xx][yy][zz] == 0 || a[xx][yy][zz]>a[x][y][z]+1){
                    a[xx][yy][zz] = a[x][y][z] + 1;
                    q.push(xx); q.push(yy); q.push(zz);
                }
            }
        }
    }
    int maxim = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                if(a[i][j][l] == 0){
                    printf("-1");
                    return 0;
                }
                maxim = max(maxim,a[i][j][l]);
            }
        }
    }
    printf("%d",maxim-1);
}
