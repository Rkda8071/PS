#include<bits/stdc++.h>
using namespace std;
int n,k,t,e;
int a[1010],d[1010],cnt[1010];
vector<int> v[1010];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++) {cnt[i] = 0; d[i] = 0;}
        for(int i=1;i<=k;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            cnt[y]++;
        }
        scanf("%d",&e);
        queue<int> q;
        for(int i=1;i<=n;i++) if(!cnt[i]) q.emplace(i);
        while(!q.empty()){
            int x = q.front(); q.pop();
            if(x==e) break;
            for(int i=0;i<v[x].size();i++){
                if(!d[v[x][i]] || d[v[x][i]]<d[x]+a[x])
                    d[v[x][i]] = d[x]+a[x];
                if(--cnt[v[x][i]] == 0) q.emplace(v[x][i]);
            }
        }
        printf("%d\n",d[e]+a[e]);
    }
    return 0;
}
