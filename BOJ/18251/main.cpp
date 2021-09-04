#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,cnt;
ll maxim = -2000000000;
ll a[300000],w[300000];
int h[300000];
void init_dfs(int x,int lev){
    if(lev==0) return;
    init_dfs(x*2, lev-1);
    a[++cnt] = w[x];
    h[cnt] = lev;
    init_dfs(x*2+1, lev-1);
}
void init(){
    scanf("%d",&n);
    for(k=1;((1<<k)-1)!=n; k++);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    init_dfs(1,k);
}
int main(){
    init();
    for(int i=1;i<=k;i++){
        for(int j=1;j<=i;j++){
            ll hap = 0LL;
            for(int x=1;x<=n;x++){
                if(i<h[x] || h[x]<j) continue;
                hap = a[x] + max(hap,0LL);
                if(maxim < hap) maxim = hap;
            }
        }
    }
    printf("%lld",maxim);
    return 0;
}
