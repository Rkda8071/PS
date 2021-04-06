#include<bits/stdc++.h>
using namespace std;
int n,m,dap;
char a[510][510];
int d[510][510];

int f(int y,int x,int z){
    if(y>n || x-z<0 || m<x+z) return y-1;
    for(int i=x-z;i<=x+z;i++)
        if(a[y][i] != '*') return y-1;
    return f(y+1,x,z+1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        dap = 0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j] = 0;
        for(int i=1;i<=n;i++) scanf(" %s",a[i]+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ang = f(i+d[i][j],j,d[i][j]);
                if(ang-i+1>d[i][j]){
                    for(int y=i;y<=ang;y++){
                        for(int x=j-(y-i);x<=j+(y-i);x++){
                            dap += ang-y+1 - d[y][x];
                            d[y][x] = ang-y+1;
                        }
                    }
                }
            }
        }
        printf("%d\n",dap);
    }
    return 0;
}
