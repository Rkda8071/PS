#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
//pair<int,int> d[110][10010]; // d[몇번째 도시][쓴 비용] = (소요 시간, 몇 번째 테케에서 돌렸는지)
int d[110][10010];
priority_queue<tp, vector<tp>, greater<tp> > pq;
vector<tp> a[110];
int n,m,k;
int main(){
    int cnt;
    scanf("%d",&cnt);
    cnt++;
    while(--cnt){
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) d[i][j] = int(1e9);
        for(int i=1;i<=k;i++){
            int u,v,c,cc;
            scanf("%d %d %d %d",&u,&v,&c,&cc);
            a[u].push_back(tp(cc,c,v)); // 소요시간, 비용, 위치
        }
        pq.emplace(0,0,1);          // 소요시간, 비용, 위치
        d[1][0] = 0; // 1번도시 초기화
        int mini = 2000000000;
        while(!pq.empty()){
            int t,c,x; // 소요시간, 비용, 위치
            tie(t,c,x) = pq.top(); pq.pop();
            if(d[x][c] < t) continue;     // 이전에 같은 조건에서 더 적은 비용이 왔으면 거름
            if(mini<d[x][c]) continue;    // 가망이 없으면 거름
            if(x==n){                     // 도착했음
                mini = d[x][c];
                continue;
            }
            for(int i=0;i<a[x].size();i++){
                int tt,cc,xx; // 목적지로 갈 때 소요시간 비용 위치
                tie(tt,cc,xx) = a[x][i];
                if(c+cc <= m && d[xx][c+cc]>t+tt){
                    d[xx][c+cc] = t+tt;
                    pq.emplace(t+tt,c+cc,xx);
                }
            }
        }
        if(mini == 2000000000) printf("Poor KCM\n");
        else printf("%d\n",mini);
    }
    return 0;
}
