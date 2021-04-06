#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int id[200100],id2[200100];
vector<int> a[200100],b[200100];

int main(){
    scanf("%d",&t);
    while(t--){
        int k,n,m;
        ll dap=0LL;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1;i<=m;i++) b[i].clear();
        for(int i=1;i<=k;i++) scanf("%d",&id[i]);
        for(int i=1;i<=k;i++) scanf("%d",&id2[i]);
        for(int i=1;i<=k;i++){
            a[id[i]].push_back(id2[i]);
            b[id2[i]].push_back(id[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                dap += (ll)(k - a[i].size() - b[a[i][j]].size() + 1);
            }
        }
        printf("%lld\n",dap/2LL);
    }

    return 0;
}
