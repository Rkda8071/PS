#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int chk[1010];
vector<int> a[1010];

void dfs(int x){
    chk[x] = 1;
    cnt++;
    for(auto i: a[x]){
        if(chk[i]) continue;
        dfs(i);
    }
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
    printf("%d",cnt-1);
    return 0;
}
