#include<bits/stdc++.h>
using namespace std;
struct A{
    int t,l,r;
    bool operator<(const A &r){
        return t<r.t;
    }
}a[110];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].t,&a[i].l,&a[i].r);
        sort(a+1,a+n+1);
        int cur = 0,l,r,chk = 0;
        l=r=m;
        for(int i=1;i<=n;i++){
            l = max(l-(a[i].t-cur),a[i].l);
            r = min(r+(a[i].t-cur),a[i].r);
            if(r<a[i].l || a[i].r<l){
                chk = 1;
                break;
            }
            cur = a[i].t;
        }
        if(chk) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
