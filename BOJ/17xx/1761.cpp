#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
vector<p> v[40010];
p sp[21][40010];
int lv[40010];
int cnt,n,q;

void dfs(int x,int pa){
    lv[x] = lv[pa] + 1;
    for(p y : v[x]){
        if(lv[y.first]) continue;
        sp[0][y.first] = make_pair(x,y.second);
        dfs(y.first,x);
    }
}

void init(){
    scanf("%d",&n);
    for(int i=1,x,y,z;i<n;i++){
        scanf("%d %d %d",&x,&y,&z);
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dfs(1, 0);
    for(int i=1; i<=20;i++){
        for(int j=1;j<=n;j++){
            sp[i][j] = sp[i-1][sp[i-1][j].first];
            sp[i][j].second += sp[i-1][j].second;
        }
    }
}

int main(){
    init();
    scanf("%d",&q);
    while(q--){
        int x,y,ans=0;
        scanf("%d %d",&x,&y);
        if(lv[x] > lv[y]) swap(x,y);
        int d = lv[y] - lv[x];
        for(int i=0;i<=20;i++){
            if(d & (1<<i)){
                ans += sp[i][y].second;
                y = sp[i][y].first;
            }
        }
        if(x == y){
            printf("%d\n",ans);
            continue;
        }
        for(int i=20;i>=0;i--){
            if(sp[i][x].first != sp[i][y].first){
                ans += sp[i][x].second + sp[i][y].second;
                x = sp[i][x].first;
                y = sp[i][y].first;
            }
        }
        printf("%d\n",ans + sp[0][x].second + sp[0][y].second);
    }
}