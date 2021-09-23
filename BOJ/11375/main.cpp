#include<bits/stdc++.h>
using namespace std;
int n,m,cur;
vector<int> a[1010];
int d[1010],cnt[1010],chk[1010];
void dfs(int x){
    for(auto y: a[x]){
        if(chk[y] == cur) continue;
        chk[y] = cur;
        if(d[y])
            dfs(d[y]);

    }
}
void init(){
    int x,nn;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&nn);
        while(nn--){
            scanf("%d",&x);
            a[i].push_back(x);
        }
    }
}
int main(){
    init();
    for(int i=1;i<=n;i++){
        cur = i;
        dfs(i);
    }
    int dap = 0;
    for(int i=1;i<=n;i++)
        dap += (d[i]) ? 1 : 0;
    printf("%d",dap);
    return 0;
}
