#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
int n;
ll lev[300100],ans,cur1,cnt1,f,s;
vector<int> a[300100];
p d[300100];
void dfs(int x){
    ll cur,cnt;
    cur = cnt = 0LL;
    for(int y : a[x]){
        if(y!=1 && lev[y]==0LL){
            lev[y] = lev[x]+1LL;
            dfs(y);
            f = d[y].first; s = d[y].second;
            ans += f;
            if(cnt) ans += cur*s + f*cnt - lev[x]*cnt*s;
            cur += f; cnt += s;
        }
    }
    d[x] = p(cur+lev[x],cnt+1LL);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}
