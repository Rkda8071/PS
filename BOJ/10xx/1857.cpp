#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int,int> tp;
int n,m;
int a[31][31],d[31][31];
int yyy[8] = {-2,-1,1,2,2,1,-1,-2}, xxx[8] = {1,2,2,1,-1,-2,-2,-1};
long long dp[31][31];
priority_queue<tp, vector<tp>, greater<tp> > pq;

// 0은 맨땅
// 1은 방석
// 2는 돌
// 3은 시작
// 4는 끝

void init(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            scanf("%d",&a[i][j]);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 3) {dp[i][j] = 1; d[i][j] = 0; pq.push(tp(0,i,j)); }
            else d[i][j] = 1e9;
        }
    }
}
void solve(){
    while(!pq.empty()){
        int t,y,x;
        tie(t,y,x) = pq.top(); pq.pop();
        if(t != d[y][x]) continue;

        for(int i=0;i<8;i++){
            int yy = y+yyy[i], xx = x+xxx[i];
            if(a[yy][xx] == 2) continue;
        }

    }
}
int main(){
    init();
    solve();
}