#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
typedef tuple<int,int,int,int> ttp;
int n,m,k;
int t[10100];
int d[10100][210]; // 위치, 적응 시간
priority_queue<ttp,vector<ttp>,greater<ttp> > pq;
vector<tp> a[20010];
void init(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]); //0춥 1적 2덥
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(tp(y,z));
        a[y].push_back(tp(x,z));
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            d[i][j] = 2000000000;
}

int main(){
    init();
    // n까지 가야댐
    pq.emplace(0,(t[1]==1)?0:k,1,t[1]);
    d[1][(t[1]==1)?0:k] = 0;
    int y,z,x,w;
    int xx,tt;
    while(!pq.empty()){
        // 시간, 온도차, 위치, 춥덥
        tie(y,z,x,w) = pq.top(); pq.pop();
        if(d[x][z] != y) continue;
        if(t[x]!=1) {z = k; w=t[x];} // 적당한 온도가 아니면 초기화

        for(int i=0;i<a[x].size();i++){
            tie(xx,tt) = a[x][i]; // 위치, 시간
            if(z-tt > 0 && abs(w-t[xx])==2) continue;
            if(d[xx][max(0,z-tt)] > y+tt){
                d[xx][max(0,z-tt)] = y+tt;
                pq.emplace(y+tt,max(0,z-tt),xx,(z-tt)>0 ? w:1);
            }
        }
    }
    int dap = d[n][0];
    for(int i=1;i<=k;i++) dap = min(dap,d[n][i]);
    printf("%d",dap);
    return 0;
}
