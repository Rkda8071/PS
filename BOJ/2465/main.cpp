#include<bits/stdc++.h>
using namespace std;
int n,nn,seg[400010],s[100010],dap[100010],a[100010];
void init(){
    scanf("%d",&n);
    for(nn=1;nn<n;nn*=2);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++) seg[nn+i] = 1;
    for(int i=nn-1;i>=1;i--) seg[i] = seg[i*2] + seg[i*2+1];
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
}
void seg_init(int x){
    while(x){
        seg[x]--;
        x/=2;
    }
}
int seg_fin(int id,int t,int x,int y){
    if(id>=nn && x==y) return id-nn;
    if(x<=t && t<=y-seg[id*2+1]) return seg_fin(id*2,t,x,y-seg[id*2+1]);
    else return seg_fin(id*2+1,t,x+seg[id*2],y);
}
int main(){
    //freopen("input.txt","r",stdin);
    init();
    for(int i=n;i>=1;i--){
        int x = seg_fin(1,s[i]+1,1,i);
        dap[i] = a[x];
        seg_init(x+nn);
    }
    for(int i=1;i<=n;i++) printf("%d\n",dap[i]);
    return 0;
}

