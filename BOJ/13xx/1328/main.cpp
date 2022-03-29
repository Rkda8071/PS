#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,maxl,maxr;
ll a[110],dap,ans[110],ncr[110][110];
void f(int id,int x,int y,int l,int r){
    if(l == maxl && r == maxr){

    }
    if(l<maxl){
        for(int i=maxl-l;i<x;i++){
            f(id-1,i,y,)
        }
    }
    if(r<maxr){

    }
}
int main(){
    scanf("%d %d %d",&n,&maxl,&maxr);
    for(int i=1;i<=n;i++){
        a[i] = 1LL;
        for(ll j=(ll)i; j>1LL; j--)
            a[i] = (a[i]*j)%1000000007LL;
    }
    for(int i=1;i<=n;i++){
        ncr[i][0] = ncr[i][i] = 1LL;
        for(int j=1;j<i;j++)
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%1000000007LL;
    }

    for(int i=maxl;i<=n-maxr+1;i++){
        f(n-1,i,i,1,1);
    }
}
