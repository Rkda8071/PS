#include<bits/stdc++.h>
using namespace std;
int a[510][510],cnt[510];
int main(){
    int n,m;
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        a[x][y] = 1;
        cnt[x] ++; cnt[y]++;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || i==k || j==k) continue;
                if(!a[i][j] && a[i][k] && a[k][j]){
                    a[i][j] = 1;
                    cnt[i]++; cnt[j]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) if(cnt[i]==n-1) cnt[0]++;
    printf("%d",cnt[0]);
    return 0;
}
