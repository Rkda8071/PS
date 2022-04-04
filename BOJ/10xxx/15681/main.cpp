#include<bits/stdc++.h>
using namespace std;
vector<int> a[100100];
int dp[100100];
bool chk[100100];

void f(int x){
    chk[x] = 1;
    for(auto y: a[x]){
        if(chk[y]) continue;
        f(y);
        dp[x] += dp[y];
    }
    dp[x]++;
}
int main(){
    int n,r,q;
    scanf("%d %d %d",&n,&r,&q);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    f(r);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",dp[x]);
    }
    return 0;
}
