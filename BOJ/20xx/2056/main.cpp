#include<bits/stdc++.h>
using namespace std;
int a[10100],d[10100];
vector<int> v[10100];
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i],&m);
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            v[i].push_back(x);
            //v[x].push_back(x); cnt[i]++;
        }
    }
    d[1] = a[1];
    for(int i=2;i<=n;i++){
        int maxim = 0;
        for(int j=0;j<v[i].size();j++)
            maxim = max(maxim,d[v[i][j]]);
        d[i] = maxim + a[i];
    }
    int dap = 0;
    for(int i=1;i<=n;i++) dap = max(dap,d[i]);
    printf("%d",dap);
    return 0;
}
