#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
vector<int> a[100100];
int e[200100],lev[200100],idx[100100],cnt;
tp d[30][200100];
void dfs(int id,int an){
    e[++cnt] = id; idx[id] = cnt;
    lev[id] = lev[an]+1;
    for(int x : a[id]){
        if(x == an) continue;
        dfs(x,id);
        e[++cnt] = id;
    }
}
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1,0);

    lev[0] = 200000000;
    for(int i=1;i<=n*2-1;i++){
        d[0][i] = tp(lev[e[i]],e[i]);
    }
    for(int k=1;k<=18;k++){
        for(int i=1;i<=cnt;i++){
            if(i+(1<<k)>cnt) break;
            d[k][i] = min(d[k-1][i],d[k-1][i+(1<<(k-1))]);
        }
    }
    scanf("%d",&m);
    while(m--){
        int x,y;
        scanf("%d %d",&x,&y);
        x = idx[x]; y = idx[y];
        if(x>y) swap(x,y);
        int k = 31 - __builtin_clz(y-x);
        printf("%d\n",get<1>(min(d[k][x], d[k][y-(1<<k)+1])));
    }
}
