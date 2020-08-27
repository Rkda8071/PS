#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dap;
struct A{
    ll x1,y1,x2,y2;
}a[10100];
bool isMeet(A x, A y){
    ll r1 = (x.y2 - x.y1) * (y.x1-x.x1)
            - (y.y1-x.y1) * (x.x2-x.x1);
    ll r2 = (x.y2 - x.y1) * (y.x2-x.x1)
            - (y.y2-x.y1) * (x.x2-x.x1);
    //printf("[%lld %lld]",r1,r2);
    if(!((r1>0LL && r2<0LL) || (r1<0LL && r2>0LL))) return false;
    if(!r1 && !r2){
        if((x.x1<=y.x1 && y.x1 <= x.x2) || (x.x1<=y.x2 && y.x2 <= x.x2)) return true;
        else return false;
    }
    r1 = (y.y2 - y.y1) * (x.x1-y.x1)
         - (x.y1-y.y1) * (y.x2-y.x1);
    r2 = (y.y2 - y.y1) * (x.x2-y.x1)
         - (x.y2-y.y1) * (y.x2-y.x1);
    //printf("[%lld %lld]",r1,r2);
    if(!((r1>0LL && r2<0LL) || (r1<0LL && r2>0LL))) return false;

    return true;
}
int main(){
    ll x1,y1,x2,y2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld %lld %lld",&y1,&x1,&y2,&x2);
        if(x1>x2 || x1==x2 && y1>y2) {swap(x1,x2); swap(y1,y2);}
        a[i] = {x1,y1,x2,y2};
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(isMeet(a[i],a[j])) dap++;

    printf("%lld", dap);
    return 0;
}
/*
2
1000000 1000000 -1000000 -1000000
1000000 -1000000 -1000000 1000000
*/
