#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll dap;
vector<int> a[300100];
int ord[300100],low[300100],cnt,root[300100],child[300100];

int dfs(int x){
    ord[x] = low[x] = ++cnt;
    for(int xx : a[x]){
        if(!ord[xx]){
            root[xx] = x;
            int res = dfs(xx);
            low[x] = min(low[x],res);
            if(ord[x]<=res) child[x]++;
        }else if(root[x] != xx){
            low[x] = min(low[x],ord[xx]);
        }
    }
    return low[x];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    if(child[1]) child[1]--;
    for(int i=1;i<=n;i++)
        if(m - a[i].size() == n-2-child[i]) dap+=(ll)i;
    printf("%lld", dap);
    return 0;
}
