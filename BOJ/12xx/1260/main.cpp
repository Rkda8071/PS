#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int chk[1010];
vector<int> a[1010];

void dfs(int x){
    chk[x] = 1;
    printf("%d ",x);
    for(auto i: a[x]){
        if(chk[i]) continue;
        dfs(i);
    }
}
void bfs(){
    queue<int> q;
    q.push(s);
    chk[s] = 2;
    while(!q.empty()){
        int x = q.front(); q.pop();
        printf("%d ",x);
        for(auto i: a[x]){
            if(chk[i] == 2) continue;
            chk[i] = 2;
            q.push(i);
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&s);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        sort(a[i].begin(), a[i].end());
    dfs(s);
    puts("");
    bfs();
    return 0;
}
