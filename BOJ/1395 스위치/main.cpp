#include<bits/stdc++.h>
using namespace std;
int n,nn,q;
int seg[400000];
int lazy[400000];
void lazy_update(int lev,int l,int r){
    if(lazy[lev]){
        seg[lev] = r-l-seg[lev] + 1;
        lazy[lev] = 0;
        if(l!=r){
            lazy[lev*2]^=1;
            lazy[lev*2+1]^=1;
        }
    }
}
int fin(int lev,int x,int y,int l,int r){
    lazy_update(lev,l,r);
    if(x>r || l>y) return 0;
    if(x<=l && r<=y) return seg[lev];
    return fin(lev*2,x,y,l,(l+r)/2) + fin(lev*2+1,x,y,(l+r)/2+1,r);
}
void update(int lev,int x,int y,int l,int r){
    lazy_update(lev,l,r);
    if(x>r || l>y) return;
    if(x<=l && r<=y){
        seg[lev] = r-l-seg[lev]+1;
        if(l!=r){
            lazy[lev*2]^=1;
            lazy[lev*2+1]^=1;
        }
        return;
    }
    update(lev*2,x,y,l,(l+r)/2); update(lev*2+1,x,y,(l+r)/2+1,r);
    seg[lev] = seg[lev*2] + seg[lev*2+1];
}
int main(){
    int o,s,t;
    scanf("%d %d",&n,&q);
    for(nn=1;nn<n;nn<<=1);
    while(q--){
        scanf("%d %d %d",&o,&s,&t);
        if(o == 0){
            update(1,s,t,1,nn);
        } else{
            printf("%d\n",fin(1,s,t,1,nn));
        }
    }
    return 0;
}
