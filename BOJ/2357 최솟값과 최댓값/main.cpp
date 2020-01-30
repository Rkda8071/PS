#include<bits/stdc++.h>
using namespace std;
int mini[400000],maxim[400000];
int n,nn,m;
int fin(int x,int y,int l,int r,int id){
    if(x>r || y<l) return 0;
    if(x<=l && r<=y) return maxim[id];
    int mid = (l+r)/2;
    return max(fin(x,y,l,mid,id*2),fin(x,y,mid+1,r,id*2+1));
}
int fin2(int x,int y,int l,int r,int id){
    if(x>r || y<l) return 2000000000;
    if(x<=l && r<=y) return mini[id];
    int mid = (l+r)/2;
    return min(fin2(x,y,l,mid,id*2),fin2(x,y,mid+1,r,id*2+1));
}
int main(){
    scanf("%d %d",&n,&m);
    for(nn=1;nn<n;nn*=2);
    for(int i=nn;i<nn+n;i++){
        scanf("%d",&mini[i]);
        maxim[i] = mini[i];
    }
    for(int i=nn+n;i<nn*2;i++) mini[i] = 2000000000;
    for(int i=nn-1;i>=1;i--) maxim[i] = max(maxim[i*2],maxim[i*2+1]);
    for(int i=nn-1;i>=1;i--) mini[i] = min(mini[i*2],mini[i*2+1]);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d %d\n",fin2(a,b,1,nn,1),fin(a,b,1,nn,1));
    }
    return 0;
}
