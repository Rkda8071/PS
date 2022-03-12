#include<bits/stdc++.h>
using namespace std;
int n,m,a[10],dap[10];

void f(int x){
    if(x == m+1){
        for(int i=1;i<=m;i++) printf("%d ",a[dap[i]]);
        puts("");
        return;
    }
    for(int i=dap[x-1];i<=n;i++){
        if(a[i-1] == a[i]) continue;
        dap[x] = i;
        f(x+1);
        dap[x] = 0;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dap[0] = 1;
    sort(a+1,a+n+1);
    f(1);
}
