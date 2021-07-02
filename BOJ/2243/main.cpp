#include<bits/stdc++.h>
using namespace std;
int n,nn;
int seg[4000000];
int fin(int lev, int tar, int l,int r){
    if(tar<l || r<tar) return -1;
    if(lev>nn) return lev;
    return max(fin(lev*2,tar,l,r-seg[lev*2+1])
                ,fin(lev*2+1,tar,l+seg[lev*2],r));
}
void init(int y,int x){
    y+=nn;
    if(x<0) x = min(seg[y],x);
    while(y){
        seg[y] += x;
        y /= 2;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(nn=1;nn<=1000000;nn*=2);
    while(t--){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==1){ //y´Â ²¨³¾ »çÅÁÀÇ ¼øÀ§
            int dap = fin(1,y,1,seg[1]) - nn;
            printf("%d\n",dap);
            init(dap,-1);
        }else{ // y¸ÀÀÇ »çÅÁÀ» x°³¸¸Å­
            scanf("%d",&x);
            init(y,x);
        }
    }
    return 0;
}
