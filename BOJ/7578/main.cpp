#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int> tp;
int n,nn;
ll seg[2000100],dap;
int a[500010];
//map<int,int> b;
tp b[500010];

ll fin(int id,int x,int y,int l,int r){
    if(x<=l && r<=y) return seg[id];
    if(y<l || r<x) return 0;
    int mid = (l+r)/2;
    return fin(id*2,x,y,l,mid) + fin(id*2+1,x,y,mid+1,r);
}
void init(int x){
    x = x+nn-1;
    while(x){
        seg[x]++;
        x/=2;
    }
}
int main(){
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        b[i] = tp(x,i);
        //b[x] = i;
    }
    sort(b+1,b+n+1);
    for(nn=1;nn<n;nn*=2);
    for(int i=1;i<=n;i++){
        x = lower_bound(b+1,b+n+1,tp(a[i],0)) - b;
        x = get<1>(b[x]);
        dap += fin(1,x,n,1,nn);
        init(x);
        //dap += fin(1,b[a[i]],n,1,nn);
        //init(b[a[i]]);
    }
    printf("%lld",dap);
    return 0;
}
//3 1 4 2 5

