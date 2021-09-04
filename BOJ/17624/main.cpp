#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
vector<int> a[5100];
int n,m,q;
int chk[5100],b[5100],d[5100][5100];
set<p> f(int x){
    chk[x] = 1;
    set<p> s,tmp,tmp2;
    s.insert(p(1,b[x]));
    for(auto xx: a[x]){
        if(chk[xx]) continue;
        tmp2.clear();
        tmp = f(xx);
        for(auto i : s)
            for(auto j : tmp)
                tmp2.insert(p(i.first+j.first, i.second+j.second));
        s.insert(tmp2.begin(),tmp2.end());
    }
    for(auto yy: s){
        int o=yy.first,t=yy.second;
        d[o][t] = 1;
    }
    return s;
}
void solve(){
    set<p> s = f(1);
    for(auto yy: s){
        int o=yy.first,t=yy.second;
        d[o][t] = 1;
    }
}
void init(){
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        b[x] = 1;
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
int main(){
    init();
    solve();
    int dap = 0;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        dap += d[x][y];
    }
    printf("%d",dap);
}
