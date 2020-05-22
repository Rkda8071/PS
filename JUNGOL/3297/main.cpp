#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll seg[4000001];

ll fin(int id,int x,int y,int l,int r){
    if(r<x || y<l) return 0L;
    if(x<=l && r<=y) return seg[id];
    int mid = (l+r)/2;
    return fin(id*2,x,y,l,mid) + fin(id*2+1,x,y,mid+1,r);
}
int main(){
    int n,q,xx,nn;
    ll x,y,z,yy;

    scanf("%d",&n);
    for(nn=1;nn<n;nn*=2);
    for(int i=1;i<=n;i++) scanf("%lld",&seg[nn+i-1]);
    for(int i=nn-1;i>=1;i--) seg[i] = seg[i*2]+seg[i*2+1];
    scanf("%d",&q);
    while(q--){
        scanf("%lld %lld %lld",&x,&y,&z);
        if(x==1){
            xx = nn + y - 1;
            yy = seg[xx] - z;
            while(xx){
                seg[xx]-=yy;
                xx/=2;
            }
        }
        else printf("%lld\n",fin(1,y,z,1,nn));

    }
    return 0;
}
