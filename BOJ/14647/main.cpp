#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[510][510];
int d[510][510],hap;
int f(int y,int x){
    int xx = a[y][x], cnt = 0;
    while(xx){
        if(xx%10 == 9) cnt++;
        xx/=10;
    }
    return cnt;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j] = f(i,j);
            hap += d[i][j];
        }
    }

    int maxim = 0, cur;
    for(int i=1;i<=n;i++){
        cur = 0;
        for(int j=1;j<=m;j++) cur+=d[i][j];
        maxim = max(maxim,cur);
    }
    for(int i=1;i<=m;i++){
        cur = 0;
        for(int j=1;j<=n;j++) cur+=d[j][i];
        maxim = max(maxim,cur);
    }
    printf("%d", hap-maxim);
    return 0;
}
