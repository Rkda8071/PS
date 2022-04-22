#include<bits/stdc++.h>
using namespace std;
int n,nn,q;
int seg[400000];
void init(int x){
    x/=2;
    while(x){
        seg[x] = seg[x*2] + seg[x*2+1];
        x/=2;
    }
}
int fin(int id,int x,int y,int l,int r){
    if(r<x || y<l) return 0;
    if(x<=l && r<=y) return seg[id];
    return fin(id*2,x,y,l,(l+r)/2) + fin(id*2+1,x,y,(l+r)/2+1,r);
}
int main(){
    scanf("%d %d",&n,&q);
    for(nn=1;nn<n;nn*=2);
    for(int i=0;i<nn;i++)
        seg[i+nn] = 1;
    for(int i=nn-1;i>=1;i--)
        seg[i] = seg[i*2]+seg[i*2+1];


    while(q--){
        int x,y;
        scanf("%d %d",&y,&x);
        if(y==1){
            scanf("%d",&y);
            printf("%d\n",fin(1,x,y,1,nn));
        }else if(y==2){
            seg[x+nn-1] = 0;
            init(x+nn-1);
        }else{
            seg[x+nn-1] = 1;
            init(x+nn-1);
        }
    }
}
