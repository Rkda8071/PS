#include<bits/stdc++.h>
using namespace std;
int n,nn,m;
int seg[2000000],lazy[2000000];
void update(int lev,int x,int y,int l,int r,int c){
    if(l>y || x>r) return;
    if(x<=l && r<=y){
        if((r-l+1)%2) seg[lev]^=c;
        if(l!=r){
            lazy[lev*2+1]^=c;
            lazy[lev*2]^=c;
        }
        return;
    }
    update(lev*2,x,y,l,(l+r)/2,c);
    update(lev*2+1,x,y,(l+r)/2+1,r,c);
    seg[lev] = seg[lev*2] ^ seg[lev*2+1];
}
void lazy_update(int lev,int x,int y){
    if(lazy[lev]){
        if((y-x+1)%2) seg[lev] ^= lazy[lev];
        if(x!=y){
            lazy[lev*2+1] ^= lazy[lev];
            lazy[lev*2] ^= lazy[lev];
        }
        lazy[lev] = 0;
    }
}
int fin(int lev,int x,int y,int l,int r){
    lazy_update(lev,l,r);
    if(l>y || x>r) return 0;
    if(x<=l && r<=y) return seg[lev];
    return fin(lev*2,x,y,l,(l+r)/2) ^ fin(lev*2+1,x,y,(l+r)/2+1,r);
}
int main(){
    scanf("%d",&n);
    for(nn=1;nn<n;nn<<=1);
    for(int i=nn;i<nn+n;i++) scanf("%d",&seg[i]);
    for(int i=nn-1;i>=1;i--) seg[i] = seg[i*2] ^ seg[i*2+1];
    scanf("%d",&m);
    int x,y,z;
    while(m--){
        /*int ang = 2;
        for(int i=1;i<nn*2;i++){
            if(i%ang==0) {puts(""); ang*=2;}
            printf("%d ",seg[i]);
        }*/
        scanf("%d %d %d",&x,&y,&z);
        ++y; ++z;
        if(y>z) swap(y,z);
        if(x==2){
            printf("%d\n",fin(1,y,z,1,nn));
        } else{
            scanf("%d",&x);
            update(1,y,z,1,nn,x);
        }
    }
    return 0;
}
