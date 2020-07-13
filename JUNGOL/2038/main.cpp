#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator<(const A &r)const{
        return x<r.x || (x==r.x && y<r.y);
    }
}a[10100];
int d[10010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[i] = {x,y};
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i] = 2000000000;
    int maxy,miny;
    for(int i=1;i<=n;i++){
        miny = maxy = a[i].y;
        for(int j=i;j>=1;j--){
            miny = min(miny,a[j].y);
            maxy = max(maxy,a[j].y);
            d[i] = min(d[i],max(max(abs(maxy),abs(miny))*2,a[i].x-a[j].x) + d[j-1]);
        }
    }
    printf("%d",d[n]);
    return 0;
}
