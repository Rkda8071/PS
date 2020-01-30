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
    int n,m,k;
    int nn;
    int x,y,a,b,xx;
    ll yy;
    scanf("%d %d",&n,&m);

    for(nn=1;nn<n;nn*=2);

    for(int i=1;i<=n;i++)
        scanf("%lld",&seg[nn+i-1]);

    for(int i=nn-1;i>=1;i--)
        seg[i] = seg[i*2]+seg[i*2+1];

    while(m--){
        scanf("%d %d %d %d",&x,&y,&a,&b);
        if(x>y) swap(x,y);
        printf("%lld\n",fin(1,x,y,1,nn));
        xx = nn + a - 1;
        yy = seg[xx] - (ll)b;
        while(xx){
            seg[xx]-=yy;
            xx/=2;
        }
    }
    return 0;
}
