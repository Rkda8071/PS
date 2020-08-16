#include<bits/stdc++.h>
using namespace std;
int n,a[30][30],hap,cnt[30],dap[30],mini;
void f(int x,int y,int cur,int t){
    if(mini>abs(t-(hap-t))){
        mini = abs(t-(hap-t));
        for(int i=1;i<=n;i++) dap[i] = cnt[i];
    }
    if(t>hap/2) return;
    if(x<cur){
        cnt[cur-1]++;
        f(x,y,cur-1,t+a[y][cur-1]);
        cnt[cur-1]--;
    }
    if(y>1){
        cnt[n]++;
        f(cur,y-1,n,t+a[y-1][n]);
        cnt[n]--;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) hap += a[i][j];
    mini = 101;
    cnt[n]++;
    f(1,n,n,a[n][n]);
    printf("%d\n",mini);
    for(int i=1;i<=n;i++) printf("%d ",dap[i]);
    return 0;
}

/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
