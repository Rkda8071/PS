#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,k;
int p[250010],uf[250010],chk[250010];
vector<int> v[250010];
ll val[250010];

int fin(int x){
    if(uf[x] == x) return x;
    return uf[x] = fin(uf[x]);
}
void uni(int x,int y){
    x = fin(x);
    y = fin(y);
    if(x == y || y == 0 || chk[y] != q) return;
    val[y] += val[x]; val[x] = 0LL;
    uf[x] = y;
}
void dfs(int x, int pre){
    p[x] = pre;
    for(int y : v[x])
        if(y != pre)
            dfs(y,x);
}
void init(){
    scanf("%d",&n);
    for(int x,y,i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        uf[i] = i;
    }
    uf[n] = n;
    dfs(1, 0);
    scanf("%d",&q); q++;
}
int main(){
    init();
    while(--q){
        ll ans = 0LL;
        scanf("%d",&k);
        vector<int> s(k+1);
        for(int i=0;i<k;i++) scanf("%d",&s[i]);
        for(int i : s) {chk[i]=q; val[i] = 1;}
        for(int i : s) uni(i, p[i]);
        for(int i : s){
            fin(i);
            if(val[uf[i]]){
                ans += val[uf[i]] * (val[uf[i]] - 1LL);
                val[uf[i]] = 0;
            }
        }
        for(int i : s) {val[i] = 0; uf[i] = i;}
        printf("%lld\n",ans/2LL);
    }
    return 0;
}