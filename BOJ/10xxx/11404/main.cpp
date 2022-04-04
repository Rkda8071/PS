#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        if(a[x][y] == 0 || a[x][y]>c) a[x][y] = c;
        //a[x][y] = c;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || !a[i][k] || !a[k][j]) continue;
                if(a[i][j]==0 || a[i][j]>a[i][k]+a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
