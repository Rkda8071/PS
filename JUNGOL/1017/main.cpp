#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    int x,r,p;
}a[510];
int d[510][510];

bool go(int x,int y) { return (a[x].x + a[x].r>= a[y].x); }
bool goback(int x,int y) { return (a[x].p && a[y].p && a[y].x - a[y].r <= a[x].x); }

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[i] = {x,y,z};
    }
    d[1][1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++) if(go(j,i)) d[1][i] += d[1][j]; // 공주한테 갈때
        for(int j=1;j<i;j++) if(goback(j,i)) d[i][1] += d[j][1]; // 공주랑 집으로
        d[1][i] %= 1000; d[i][1] %= 1000;
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<i;j++){
            if(go(j,i+1)) d[i][i+1] += d[i][j];
            if(goback(j,i+1)) d[i+1][i] += d[j][i];
        }
        d[i][i+1] %= 1000; d[i+1][i] %= 1000;
        for(int j=i+1;j<n;j++){
            for(int l=j;l>=1;l--){
                if(go(l,j+1)) d[i][j+1] += d[i][l];
                d[i][j+1] %= 1000;
            }
            for(int l=j;l>=1;l--){
                if(goback(l,j+1)) d[j+1][i] += d[l][i];
                d[j+1][i] %= 1000;
            }

        }
    }
    int dap = 0;
    for(int i=1;i<n;i++){
        if(go(i,n)) dap += d[n][i];
        dap %= 1000;
    }
    printf("%d",dap);
    return 0;
}
