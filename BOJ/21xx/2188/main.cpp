#include<bits/stdc++.h>
using namespace std;
int n,m;
int chk[220],d[220],cur;
vector<int> v[220];

bool dfs(int x){
    chk[x] = cur;
    for(int to: v[x]){
        if(!d[to] || (chk[d[to]] != cur && dfs(d[to]) )){
            d[to] = x;
            return true;
        }
    }
    return false;
}
void init(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int x,k;
        scanf("%d",&k);
        while(k--){
            scanf("%d",&x);
            v[i].push_back(x);
        }
    }
}

int main(){
    int dap = 0;
    init();
    for(int i=1;i<=n;i++){
        cur = i;
        if(dfs(i)) dap++;
    }
    printf("%d",dap);
}
