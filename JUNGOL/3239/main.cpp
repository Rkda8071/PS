#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
tp seg[400100];
int n,m,nn;
void init(int id,int x){
    seg[id] = tp(x,id-nn+1);
    while(id>1){
        id/=2;
        seg[id] = min(seg[id*2],seg[id*2+1]);
    }
}
tp fin(int id,int x,int y,int l,int r){
    if(x<=l && r<=y) return seg[id];
    if(r<x || y<l) return tp(2000000000,-1);
    int mid = (l+r)/2;
    return min(fin(id*2,x,y,l,mid),fin(id*2+1,x,y,mid+1,r));
}
int main(){
    int x,y,z;
    scanf("%d %d",&n,&m);
    for(nn=1;nn<n;nn*=2);
    for(int i=1;i<=nn*2;i++) seg[i] = tp(2000000000,-1);
    while(m--){
        scanf("%d",&x);
        if(x==1){ // y번째에 z입력
            scanf("%d %d",&y,&z);
            init(nn+y-1,z);
        }else if(x==2){
            scanf("%d %d",&y,&z);
            tp ang = fin(1,y,z,1,nn);
            if(get<0>(ang)!=2000000000) printf("%d\n",get<1>(ang));
        }else{
            scanf("%d %d",&y,&z);
            tp ang = fin(1,y,z,1,nn);
            if(get<0>(ang)!=2000000000)
                init(nn+get<1>(ang)-1,2000000000);
            //if(get<1>(ang)!=-1) printf("%d\n",get<1>(ang));
        }
    }
    return 0;
}
