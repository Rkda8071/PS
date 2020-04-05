#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n=6,m;
int a[10][10],yyy[4]={1,0,-1,0},xxx[4]={0,-1,0,1};
int d[7][5]={{0},{1,2,3,4},{1,5,9,6},{2,6,10,7},
             {3,7,11,8},{4,8,12,5},{12,11,10,9}};
int s[10];
tp fin(int x,int y){
    for(int i=1;i<=6;i++){
        if(i==x) continue;
        for(int j=0;j<4;j++)
            if(d[i][j]==y) return tp(i,j);
    }
    return tp(0,0);
}
void g(int y,int x,int chk){
    for(int i=0;i<4;i++){
        int yy = y+yyy[(i+chk)%4],xx = x+xxx[(i+chk)%4];
        int cur = a[y][x], ang = a[yy][xx];
        if(!s[ang] && ang>0){
            tie(s[ang],m) = fin(s[cur],d[s[cur]][i]);
            g(yy,xx,((i+chk+2-m)%4));
        }
    }
}
void f(){
    s[1] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j] == 1) {g(i,j,0); return;}
}
int main(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    f();
    int chk[10]={0},dap;
    for(int i=1;i<=n;i++){
        if(chk[s[i]] || s[i]==0){
            printf("0");
            return 0;
        } else chk[s[i]] = 1;
        if(s[i]==6) dap = i;
    }
    printf("%d",dap);
    return 0;
}
