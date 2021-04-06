#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
tuple<ll,int> a[100010];
int dap[100010];
ll n,m,s,hap;
bool f(int i,ll e,int pre){
    if(i==m+1) return true;
    int x; ll y;
    tie(y,x) = a[i];
    if(hap-y>=n-max(i+y-1,e)){
        e = max(i+y-1,e);
        if(e>n) return false;
        hap -= y;
        dap[x] = i;
        pre = i+1;
        return f(i+1,e,pre);
    } else{
        hap = 0;
        for(int j=pre;j<=e+1;j++){
            if(max(j+y-1,e)>n) return false;
            dap[x] = j;
            if(i==m && j+y-1!=n) continue;
            if(f(i+1,max(j+y-1,e),j+1)) return true;
        }
    }
    return false;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        ll x;
        scanf("%lld",&x); hap += x;
        a[i] = make_tuple(x,i);
    }
    sort(a+1,a+m+1,greater<tuple<int,int> >());
    ll e = 0;
    if(!f(1,0,1)) printf("-1");
    else for(int i=1;i<=m;i++) printf("%d ",dap[i]);
    return 0;
}
