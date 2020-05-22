#include<bits/stdc++.h>
using namespace std;
int nn,seg[200000];
int fin(int lev,int x,int y,int l,int r){
    if(x<=l && r<=y) return seg[lev];
    if(r<x || y<l) return 0;
    int mid = (l+r)/2;
    return max(fin(lev*2,x,y,l,mid),fin(lev*2+1,x,y,mid+1,r));
}
int main(){
    int n,q,x,y;
    scanf("%d %d",&n,&q);
    for(nn=1;nn<n;nn*=2);
    for(int i=nn;i<nn+n;i++) scanf("%d",&seg[i]);
    for(int i=nn-1;i>=1;i--)
        seg[i] = max(seg[i*2],seg[i*2+1]);
    while(q--){
        scanf("%d %d",&x,&y);
        printf("%d\n",fin(1,x,y,1,nn));
    }
    return 0;
}
