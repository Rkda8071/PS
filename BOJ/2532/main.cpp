#include<bits/stdc++.h>
#define M 2000000000
using namespace std;
struct A{
    int s,e;
    bool operator<(const A &r)const{
        return e<r.e || (e==r.e && s>r.s);
    }
}a[500100];
int n,maxim,d[500100];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%*d %d %d",&a[i].s,&a[i].e);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i] = M;
    for(int i=1;i<=n;i++){
        if(a[i-1].e == a[i].e && a[i-1].s == a[i].s) continue;
        int x = upper_bound(d,d+n,M-a[i].s) - d;
        d[x] = M-a[i].s;
        maxim = max(x,maxim);
    }
    printf("%d",maxim);
    return 0;
}
