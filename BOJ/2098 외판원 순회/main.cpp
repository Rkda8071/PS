#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define min(x,y) (x>y) ? y : x

int a[20][20];
int d[17][1<<16];
int n,mini = INF;
int f(int cur,int x){
    if(d[cur][x]) return d[cur][x];
    if(x&1){
        if(x!=(1<<n)-1) return INF;
        return 0;
    }
    d[cur][x] = INF;
    for(int i=0;i<n;i++){
        if(a[cur][i]>0 && (x&(1<<i))==0){
            d[cur][x] = min(d[cur][x],f(i,x|(1<<i)) + a[cur][i]);
        }
    }
    return d[cur][x];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    memset(d, 0, sizeof(d));
    printf("%d",f(0,0));

    return 0;
}
