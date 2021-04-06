#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
int n,nn;
pp seg[400000];

void init(){
    scanf("%d",&n);
    for(nn=1;nn<n;nn*=2);
    for(int i=nn;i<nn+n;i++){
        int x;
        scanf("%d",&x);
        seg[i] = pp(x,i-nn+1);
    }
    for(int i=nn+n;i<=nn*2;i++) seg[i] = pp(2000000000,0);
    for(int i=nn-1;i>=1;i--) seg[i] = min(seg[i*2],seg[i*2+1]);
}

pp fin(int id,int x,int y,int l,int r){
    if(r<x || y<l) return pp(2000000000,0);
    if(x<=l && r<=y) return seg[id];
    int mid = (l+r)/2;
    return min(fin(id*2,x,y,l,mid),fin(id*2+1,x,y,mid+1,r));
}

int main(){
    init();
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1){
            seg[nn+y-1] = pp(z,y);
            y = (nn+y-1)/2;
            while(y){
                seg[y] = min(seg[y*2+1],seg[y*2]);
                y/=2;
            }
        }else printf("%d\n",get<1>(fin(1,y,z,1,nn)));
    }
    return 0;
}
