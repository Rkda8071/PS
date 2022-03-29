#include<bits/stdc++.h>
using namespace std;

struct A{
    int x,y;
    bool operator<(const A &r){
        return x<r.x;
    };
}a[100100];
int d[100100],chk[500100],c[500100],maxim;
stack<int> s;

int main(){
    int n,m;
    int x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        a[i] = {x,y};
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        x = lower_bound(d,d+maxim,a[i].y) - d;
        if(maxim == x) maxim++;
        d[x] = a[i].y;
        chk[d[x]] = x ? d[x-1] : 0;
    }
    printf("%d\n",n-maxim);
    for(int i=d[maxim-1]; i; i = chk[i]) c[i] = 1;
    for(int i=0;i<n;i++) if(!c[a[i].y]) printf("%d\n",a[i].x);
    return 0;
}
