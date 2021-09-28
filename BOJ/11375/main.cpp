#include<bits/stdc++.h>
using namespace std;
int n,m,cur;
vector<int> v[1010];
int d[1010],chk[1010];
bool dfs(int from){
    chk[from] = cur;
    for(auto to : v[from]){
        if(d[to] == 0 || chk[d[to]] != cur && dfs(d[to])){
            d[to] = from;
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
        if(dfs(i))
            dap++;
    }
    printf("%d",dap);
}
