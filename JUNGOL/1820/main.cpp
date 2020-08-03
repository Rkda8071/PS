#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
} a[1010];

int dis(int x,int y){ return abs(a[x].x - a[y].x) + abs(a[x].y - a[y].y); }
int d[1010][1010],path[1010][1010];
int main(){
    int n,m;
    int y,x;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        a[i] = {x,y};
    }

    a[0] = {1,1}; a[n+1] = {n,n};
    d[0][1] = dis(1,n+1);
    d[1][0] = dis(1,0);

    for(int i=2;i<=m;i++){
        d[0][i] = d[0][i-1] + dis(i,i-1);
        d[i][0] = d[i-1][0] + dis(i,i-1);
    }
    for(int i=1;i<m;i++){
        d[i][i+1] = d[i][0] + dis(i+1,n+1);
        for(int j=1;j<i;j++){
            if(d[i][i+1] > d[i][j] + dis(j,i+1)){
                d[i][i+1] = d[i][j] + dis(j,i+1);
                path[i][i+1] = j;
            }
        }
        for(int j=i+2;j<=m;j++) d[i][j] = d[i][j-1] + dis(j,j-1);
        for(int j=i+2;j<=m;j++) path[i][j] = j-1;
        d[i+1][i] = d[0][i] + dis(i+1,0);
        for(int j=1;j<i;j++){
            if(d[i+1][i]>d[j][i] + dis(j,i+1)){
                d[i+1][i] = d[j][i] + dis(j,i+1);
                path[i+1][i] = j;
            }
        }
        for(int j=i+2;j<=m;j++) d[j][i] = d[j-1][i] + dis(j,j-1);
        for(int j=i+2;j<=m;j++) path[j][i] = j-1;
    }
    y=0,x=m;
    int sw = 0;
    stack<int> dap;
    for(int i=0;i<m;i++){
        if(d[y][x]>d[m][i]) {y=m; x=i;}
        if(d[y][x]>d[i][m]) {y=i; x=m;}
    }
    printf("%d\n",d[y][x]);
    while(y || x){
        if(y>x){
            y = path[y][x];
            dap.push(1);
        }else if(y<x){
            x = path[y][x];
            dap.push(2);
        }
    }
    while(!dap.empty()){
        printf("%d\n",dap.top());
        dap.pop();
    }
    return 0;
}
