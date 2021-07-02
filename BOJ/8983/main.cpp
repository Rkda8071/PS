#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator < (const A &r){
        return x<r.x;
    }
}a[100100];
int b[100100];
int main(){
    int n,m,l,ans=0;
    scanf("%d %d %d",&m,&n,&l);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[i] = {x,y};
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i=1;i<=n;i++){
        int x = lower_bound(b+1,b+m+1,a[i].x) - b;
        if(x==m+1) x--;
        if(abs(a[i].x-b[x])+a[i].y <= l){
            ans++;
            continue;
        }
        if(x>1) x--;
        if(abs(a[i].x-b[x])+a[i].y <= l)
            ans++;
    }
    printf("%d",ans);
    return 0;
}
