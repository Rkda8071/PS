#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int> tp;
ll a[200100];
int n,t,chk[200100];
int main(){
    scanf("%d",&t);
    while(t--){
        ll hap = 0LL;
        scanf("%d",&n);
        priority_queue<tp,vector<tp>,greater<tp> > pq;
        queue<int> q;
        for(int i=1;i<=n;i++) chk[i] = 0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) pq.emplace(a[i],i);
        while(!pq.empty()){
            ll y; int x;
            tie(y,x) = pq.top(); pq.pop();
            if(hap<y){
                while(!q.empty()){
                    chk[q.front()] = 1;
                    q.pop();
                }
            }
            hap+=y;
            q.push(x);
        }
        int dap = 0;
        for(int i=1;i<=n;i++) if(!chk[i]) dap++;
        printf("%d\n",dap);
        for(int i=1;i<=n;i++) if(!chk[i]) printf("%d ",i);
        puts("");
    }
    return 0;
}
