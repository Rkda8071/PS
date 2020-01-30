#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nn,n,q,qq;
ll seg[4000000],lazy[4000000];
void lazy_update(int lev,int x,int y){
    if(lazy[lev]){
        seg[lev] += lazy[lev] * (y-x+1);
        if(x!=y){
            lazy[lev*2+1] += lazy[lev];
            lazy[lev*2] += lazy[lev];
        }
        lazy[lev] = 0;
    }
}
void range_update(int lev,int x,int y,int l,int r,ll diff){
    lazy_update(lev,l,r);
    if(x>r || l>y) return;
    if(l==r){
        seg[lev] += diff;
        return;
    } if(x<=l && r<=y){
        seg[lev] += diff*(r-l+1);
        lazy[lev*2] += diff;
        lazy[lev*2+1] += diff;
        return;
    }
    //seg[lev] += diff*(min(y,r)-max(x,l)+1);
    range_update(lev*2,x,y,l,(l+r)/2,diff);
    range_update(lev*2+1,x,y,(l+r)/2+1,r,diff);
    seg[lev] = seg[lev*2+1] + seg[lev*2];
}
ll lazy_fin(int lev,int x,int y,int l,int r){
    lazy_update(lev,l,r);
    if(x>r || l>y) return 0;
    if(x<=l && r<=y) return seg[lev];// + lazy[lev];
    return lazy_fin(lev*2,x,y,l,(l+r)/2) + lazy_fin(lev*2+1,x,y,(l+r)/2+1,r);
}
int main(){
    ll diff;
    scanf("%d %d %d",&n,&q,&qq);
    q+=qq;
    for(nn=1;nn<n;nn<<=1);
    for(int i=nn;i<nn+n;i++) scanf("%lld",&seg[i]);
    for(int i=nn-1;i>=1;i--) seg[i]=seg[i*2]+seg[i*2+1];

    while(q--){
        int x,y;
        scanf("%d %d %d",&qq,&x,&y);
        if(qq==2) printf("%lld\n",lazy_fin(1,x,y,1,nn));
        else {
            scanf("%lld",&diff);
            range_update(1,x,y,1,nn,diff);
        }
    }
    return 0;
}
