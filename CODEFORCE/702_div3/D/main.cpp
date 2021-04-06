#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[110],d[110];
void f(int l,int r,int id){
    if(l>r) return;
    int m=l;
    for(int i=l+1;i<=r;i++) if(a[m]<a[i]) m=i;
    d[m] = d[id] + 1;
    f(l,m-1,m); f(m+1,r,m);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) d[i] = 0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i] == n){
                f(1,i-1,i);
                f(i+1,n,i);
                break;
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",d[i]);
        puts("");
    }
    return 0;
}
