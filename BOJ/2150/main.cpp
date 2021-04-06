#include<bits/stdc++.h>
using namespace std;
int v,e;
int chk[10010];
vector<int> a[10010],r[10010],ang;
vector<vector<int> > dap;
stack<int> s;

void dfs(int x){
    chk[x] = 1;
    for(int xx : a[x])
        if(!chk[xx])
            dfs(xx);
    s.push(x);
}
void f(int x){
    chk[x] = 2;
    for(int xx:r[x])
        if(chk[xx] != 2)
            f(xx);
    ang.push_back(x);
}
int main(){
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        r[y].push_back(x);
    }

    //dfs(1);
    for(int i=1;i<=v;i++)
        if(!chk[i]) dfs(i);

    while(!s.empty()){
        while(!s.empty() && chk[s.top()] == 2) s.pop();
        if(s.empty()) break;

        ang.clear();
        f(s.top()); s.pop();
        sort(ang.begin(),ang.end()); ang.push_back(-1);
        dap.push_back(ang);
    }
    sort(dap.begin(),dap.end());
    printf("%d\n",dap.size());
    for(int i=0;i<dap.size();i++){
        for(int x : dap[i])
            printf("%d ",x);
        puts("");
    }
    return 0;
}
