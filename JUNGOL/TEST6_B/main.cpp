#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100100],b[100100],m[100100];
ll seg[400100],n,nn,dap;
ll fin(int x,int y,int l,int r,int id){ // 목표, 현재 범위, 현재 위치
    if(y<l || r<x) return 0LL;
    if(x<=l && r<=y) return seg[id];
    int mid = (l+r)/2;
    return fin(x,y,l,mid,id*2) + fin(x,y,mid+1,r,id*2+1);
}
void del(int x){
    while(x){
        seg[x]--;
        x/=2;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        int cnt = 0;
        dap = 0LL;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) b[i] = a[i];
        sort(b+1,b+n+1);

        for(nn=1;nn<n;nn*=2);
        for(int i=nn;i<=nn*2;i++) seg[i] = 0LL;

        for(int i=1;i<=n;i++){
            if(b[i]!=b[i-1]) ++cnt;
            m[i] = cnt;
            seg[nn + m[i] - 1]++;
        }
        for(int i=nn-1;i>=1;i--)
            seg[i] = seg[i*2] + seg[i*2+1];
        for(int i=n;i>=1;i--){
            int x = lower_bound(b+1,b+n+1,a[i]) - b;
            dap += fin(m[x]+1,n,1,nn,1);
            del(nn + m[x]- 1);
        }
        printf("%lld\n",dap);
    }
    return 0;
}
