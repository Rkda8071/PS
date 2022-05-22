#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int t,tt,n,r,ans;
int seq[12],chk[12],res[12],ang[12];
struct A{
    int y,x;
};
A a[12],b[12];
int dis(A x, A y){return abs(x.x - y.x) + abs(x.y - y.y);}
bool f(int x);

bool g(int x){
    int maxim = dis(a[seq[x]],b[0]);
    for(int i=1;i<=n;i++){
        if(ang[i]) continue;
        maxim = min(maxim, dis(a[seq[x]],b[i]));
    }
    for(int i=1;i<=n;i++){
        if(!ang[i] && dis(a[seq[x]],b[i]) == maxim){
            res[x] = i + 1; ang[i] = 1;
            if(f(x+1)) return true;
            res[x] = 0; ang[i] = 0;
        }
    }
    return false;
}

bool f(int x){
    if(x==n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(!chk[i]){
            chk[i] = 1;
            seq[x] = i;
            if(g(x)) return true;
            
            chk[i] = seq[x] = 0;
        }
    }
    return false;
}
int main(){
    scanf("%d",&t);
    for(tt=1; tt<=t; tt++){
        printf("Case #%d: ",tt);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int y,x;
            scanf("%d %d",&x,&y);
            a[i] = {y,x};
        }
        for(int i=0;i<=n;i++){
            ang[i] = chk[i] = 0;
            int y,x;
            scanf("%d %d",&x,&y);
            b[i] = {y,x};
        }
        if(f(0)){
            printf("POSSIBLE\n");
            for(int i=0;i<n;i++){
                printf("%d %d\n",seq[i]+1,res[i]);
            }
        }else{
            printf("IMPOSSIBLE\n");
        }
    }
}
