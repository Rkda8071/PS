#include<bits/stdc++.h>
using namespace std;
vector<int> a[10010],r[10010],g[10010];
int chk[10010],cnt;
stack<int> s;
void dfs(int x){
    chk[x] = 1;
    for(int i=0;i<a[x].size();i++)
        if(!chk[a[x][i]]) dfs(a[x][i]);
    s.push(x);
}
void rdfs(int x){
    chk[x] = 2;
    for(int i=0;i<r[x].size();i++)
        if(chk[r[x][i]]!=2) rdfs(r[x][i]);
    g[cnt].push_back(x);
}
int main(){
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        r[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!chk[i]) dfs(i);
    while(!s.empty()){
        int x = s.top(); s.pop();
        if(chk[x]!=2){
            ++cnt;
            rdfs(x);
        }
    }
    for(int i=1;i<=n;i++) chk[i] = 0;
    ++cnt;
    rdfs(g[cnt-1][0]);
    if(g[cnt].size()==n) printf("%d",g[cnt-1].size());
    else printf("0");
    return 0;
}
