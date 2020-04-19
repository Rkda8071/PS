#include<bits/stdc++.h>
using namespace std;
int a[10100];
int n,k,ang=1;
queue<int> dap;
int fin(int x){
    if(a[x]==x) return x;
    return a[x] = fin(a[x]);
}
void uni(int x){
    if(x==n) a[x] = fin(a[1]);
    else a[x] = fin(a[x+1]);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) a[i] = i;
    ang = k;
    dap.push(ang);
    uni(ang);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(ang==n) ang = fin(a[1]);
            else ang = fin(a[ang+1]);
        }
        uni(ang);
        dap.push(ang);
    }
    while(!dap.empty()){
        printf("%d ",dap.front());
        dap.pop();
    }
    return 0;
}
