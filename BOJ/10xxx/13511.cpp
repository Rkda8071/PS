#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> p;
vector<p> a[100010];
int n,m;
int lv[100010],sp[100010][21];
ll w[100010];
void dfs(int x,int p){
    lv[x] = lv[p] + 1;
    for(auto y : a[x]){
        if(lv[y.first]) continue;
        w[y.first] = w[x] + (ll)y.second;
        sp[y.first][0] = x;
        dfs(y.first, x);
    }
}
void init(){
    scanf("%d",&n);
    for(int x,y,z,i=1;i<n;i++){
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
    }
    dfs(1,0);
    for(int i=1;i<20;i++)
        for(int j=1;j<=n;j++)
            sp[j][i] = sp[sp[j][i-1]][i-1];
}
int fin(int x,int y){
    if(lv[x]<lv[y]) swap(x,y);
    int d = lv[x] - lv[y];
    for(int i=0;i<20;i++)
        if(d & (1<<i))
            x = sp[x][i];
    if(x == y) return x;
    for(int i=19;i>=0;i--){
        if(sp[x][i] != sp[y][i]){
            x = sp[x][i];
            y = sp[y][i];
        }
    }
    return sp[x][0];
}
int main(){
    init();
    scanf("%d",&m);
    while(m--){
        int x,y,z,lca;
        scanf("%d %d %d",&x,&y,&z);

        lca = fin(y,z);
        if(x==1)
            printf("%lld\n",w[y] + w[z] - w[lca]*2);
        else{
            scanf("%d",&x);
            --x;
            if(lv[y] - lv[lca] >= x){
                for(int i=0;i<20;i++){
                    if(x & (1<<i))
                        y = sp[y][i];
                }
                printf("%d\n",y);
            }else{
                x = lv[z] - lv[lca] - (x - lv[y] + lv[lca]);
                for(int i=0;i<20;i++){
                    if(x & (1<<i))
                        z = sp[z][i];
                }
                printf("%d\n",z);
            }
        }
    }
    return 0;
}