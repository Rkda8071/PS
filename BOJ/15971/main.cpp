#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,s,e,dap,m;
int chk[100100];
vector<tp> a[100100];

bool dfs(int x){
    chk[x] = 1;
    if(x==e)
        return true;
    for(auto i=a[x].begin(); i!=a[x].end(); i++){
        int y,d;
        tie(y,d) = *i;
        if(!chk[y] && dfs(y)){
            dap += d;
            m = max(m,d);
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n,&s,&e);
    for(int i=1;i<n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(tp(y,z));
        a[y].push_back(tp(x,z));
    }
    dfs(s);
    printf("%d",dap-m);
}
