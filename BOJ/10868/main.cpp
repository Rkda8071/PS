#include<bits/stdc++.h>
#define MAX 2000000000
using namespace std;
int seg[400000];
int nn,n,m;
int fin(int lev,int x,int y,int l,int r){
    if(r<x || y<l) return MAX;
    if(x<=l && r<=y) return seg[lev];
    return min(fin(lev*2,x,y,l,(l+r)/2),fin(lev*2+1,x,y,(l+r)/2+1,r));
}
int main(){
    int a,b;
    scanf("%d %d",&n,&m);
    for(nn=1;nn<n;nn*=2);
    for(int i=nn;i<nn+n;i++) scanf("%d",&seg[i]);
    for(int i=nn+n;i<nn*2;i++) seg[i] = MAX;
    for(int i=nn-1;i>=1;i--) seg[i] = min(seg[i*2],seg[i*2+1]);
    while(m--){
        scanf("%d %d",&a,&b);
        if(a>b) swap(a,b);
        printf("%d\n",fin(1,a,b,1,nn));
    }
    return 0;
}
