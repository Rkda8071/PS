#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator<(const A &r){
        return (x+y<r.x+r.y);
    }
}a[1010];
int dis(int x,int y){return (a[x].x-a[y].x)*(a[x].x-a[y].x)
                                    +(a[x].y-a[y].y)*(a[x].y-a[y].y);}
int n,k,l,r,mid;
bool chk(){
    int fr = 0, re = 1;
    int d[1010] = {0};
    while(fr<re){
        if(dis(fr,n+1)<=mid*mid){
            return d[fr]<=k;
        }
        for(int i=re;i<=n;i++){
            if(dis(fr,i)<=mid*mid){
                swap(a[re],a[i]);
                d[re++] = d[fr] + 1;
            }
        }
        fr++;
    }
    return false;
}
int main(){
    int x,y;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].x,&a[i].y);
    a[0] = {0,0}; a[n+1] = {10000,10000};
    sort(a+1,a+n+1);
    r = 20000; l = 0;
    while(1){
        if(r<=l){break;}
        mid = (r+l)/2;
        if(chk()) r = mid;
        else l = mid + 1;
    }
    printf("%d",l/10 + ((l%10>0) ? 1 : 0));
    return 0;
}
