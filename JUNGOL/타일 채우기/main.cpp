#include<bits/stdc++.h>
using namespace std;
int d[600][600];
int xx[5] = {0,0,1,0,1},yy[5] = {0,0,0,1,1};
int sy,sx;
void f(int n,int y,int x){
    int k;
    if(n==0) {
        return;
    }
    for(int i=1;i<=4;i++){
        int yyy = y+yy[i]*n, xxx = x+xx[i]*n;
        if(yyy<=sy && sy<yyy+n && xxx<=sx && sx<xxx+n){
            f(n/2,yyy,xxx);
            k = i;
            break;
        }
    }
    for(int i=1;i<=4;i++){
        int yyy = y+yy[i]+n-1, xxx = x+xx[i]+n-1;
        if(i!=k) {
            d[yyy][xxx] = k;
            sy = yyy; sx = xxx;
            f(n/2,y+yy[i]*n,x+xx[i]*n);
        }
    }
}
int main(){
    int n;
    scanf("%d %d %d",&n,&sy,&sx);
    sy++; sx++;
    if(n>1) f(n/2,1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d ",d[i][j]);
        puts("");
    }
    return 0;
}
