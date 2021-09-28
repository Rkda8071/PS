#include<bits/stdc++.h>
using namespace std;
int n,m,cur;
vector<int> v[1010];
int d[1010],chk[1010];
void dfs(int x){
    for(auto xx : v[x]){
        if(chk[xx] == cur) continue;
        chk[xx] = cur;
        dfs(d[xx]);
        d[xx] = x;
        break;
    }
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
    init();
    for(int i=1;i<=n;i++){
        cur = i;
        dfs(i);
    }

    int sum = 0;
    for(int i=1;i<=n;i++)
        sum += (d[i]) ? 1 : 0;
    printf("%d",sum);
}
