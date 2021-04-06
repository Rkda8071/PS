#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int> tp;
int t,n;
int cnt[100100],chk[100100];
ll w[100100];
vector<int> v[100100];

int main(){
    scanf("%d",&t);
    t++;
    while(--t){
        ll dap = 0LL;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++){ scanf("%lld",&w[i]); dap+=w[i]; }
        for(int i=1;i<n;i++){
            int x,y; scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        priority_queue<tp> pq;
        for(int i=1;i<=n;i++){
            cnt[i] = v[i].size();
            if(cnt[i]!=1) pq.emplace(w[i],i);
        }
        //if(n==2)
        printf("%lld ",dap);
        while(!pq.empty()){
            ll y; int x;
            tie(y,x) = pq.top(); pq.pop();
            int ang = 0;
            for(int i=0;i<v[x].size();i++){
                if(cnt[v[x][i]]){
                    cnt[v[x][i]]--;
                    ang++;
                }else if(chk[v[x][i]]==t){
                    chk[v[x][i]] = 0;
                    ang++;
                }
            }
            for(int i=1;i<ang;i++){
                dap+=y;
                printf("%lld ",dap);
                chk[x] = t;
            }
            cnt[x] = 0;
        }
        puts("");
    }
    return 0;
}
