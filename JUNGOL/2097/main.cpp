#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,m;
int a[101][101],d[101],path[101],chk[101];
priority_queue<tp, vector<tp>, greater<tp> > pq;
void in(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    return;
}
void f(){ // 다익스트라
    pq.emplace(0,1);
    while(!pq.empty()){
        int v,x;
        tie(v,x) = pq.top(); pq.pop();
        if(chk[x]!=0) continue;
        chk[x] = 1;
        for(int i=1;i<=n;i++){
            if(i==x) continue;
            if(chk[i]==0 && (d[i] == 0 || d[x] + a[x][i]<d[i])){
                d[i] = d[x]+a[x][i];
                path[i] = x;
                pq.emplace(d[x]+a[x][i],i);
            }
        }
    }
}
void trace(int x){
    if(x==0) return;
    trace(path[x]);
    printf("%d ",x);
}
int main(){
    in();
    f();
    printf("%d\n",d[m]);
    trace(m);
    return 0;
}
