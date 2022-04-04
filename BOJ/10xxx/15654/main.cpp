#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10],chk[10],b[10];
void f(int x){
    if(x==m){
        for(int i=0;i<m;i++) printf("%d ",b[a[i]]);
        puts("");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!chk[i]){
            chk[i] = 1; a[x] = i;
            f(x+1);
            chk[i] = 0; a[x] = 0;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(b+1,b+n+1);
    f(0);
    return 0;
}
