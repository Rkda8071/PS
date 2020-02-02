#include<bits/stdc++.h>
using namespace std;

struct A{
    int v,x;
    bool operator<(const A &r){
        return v<r.v || (v==r.v && x<r.x);
    }
}a[300100];

int main(){
    int t,n,x;
    int l,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            a[i] = {x,i};
        }
        sort(a+1,a+n+1);
        l = 1; r = n; x = 0;
        for(int i=1;i<=n;i++){
            if(n-a[i].x > a[i].v) l = a[i].x+1;
            if(a[i].x-1 > a[i].v) r = a[i].x-1;
            if(l<=a[i].x && a[i].x<=r) {x = 1; break;}
            if(l>r) break;
        }
        if(x) printf("Yes");
        else printf("No");
        puts("");
    }
}
