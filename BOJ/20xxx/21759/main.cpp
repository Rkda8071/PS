#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> v[200010];
ll dp[200010],a[200010];

ll dfs(int x){
    for(int l : v[x]){
        ll ang = dfs(l);
        if(ang>0) dp[x] += ang;
    }
    return dp[x] = dp[x] + a[x];
}

int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d %d",&x,&y);
        a[i] = x;
        if(y != -1) v[y].push_back(i);
    }
}
