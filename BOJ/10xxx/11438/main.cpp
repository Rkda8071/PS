#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,m,nn,cnt;
vector<int> a[100010];
tp seg[800010];
int idx[100100];
void dfs(int lev,int id){
    seg[nn+cnt] = tp(lev,id);
    idx[id] = ++cnt;
    for(int i=0;i<a[id].size();i++){
        if(idx[a[id][i]]) continue;
        dfs(lev+1,a[id][i]);
        seg[nn+cnt] = tp(lev,id);
        ++cnt;
    }
    return;
}
tp fin(int id,int x,int y,int l,int r){
    if(r<x || y<l) return tp(2000000,0);
    if(x<=l && r<=y) return seg[id];
    int mid = (l+r)/2;
    return min(fin(id*2,x,y,l,mid),fin(id*2+1,x,y,mid+1,r));
}
int main(){
    int x,y;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(nn=1;nn<n*2;nn*=2);
    dfs(0,1);
    for(int i=nn+cnt;i<=nn*2;i++) seg[i] = tp(2000000,0);
    for(int i=nn-1;i>=1;i--)
        seg[i] = min(seg[i*2+1],seg[i*2]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        if(idx[x]>idx[y]) swap(x,y);
        tie(x,y) = fin(1,idx[x],idx[y],1,nn);
        printf("%d\n",y);
    }
    return 0;
}
