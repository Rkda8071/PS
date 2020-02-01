#include<bits/stdc++.h>
using namespace std;
int n;
int a[200200],d[2][200200];
vector<int> r[200200];
priority_queue<int,vector<int>,greater<int> > pq;
void f(int x){
    d[1][x] = a[x];
    for(int i=r[x].size()-1;i>=0;i--){
        f(r[x][i]);
        d[1][x] += d[0][r[x][i]];
        d[0][x] += max(d[0][r[x][i]],d[1][r[x][i]]);
    }
    return;
}
void trace(int x,int v){
    if(v) {
        pq.push(x);
        for(int i=r[x].size()-1;i>=0;i--) trace(r[x][i],0);
    } else{
        for(int i=r[x].size()-1;i>=0;i--){
            if(d[0][r[x][i]]>d[1][r[x][i]]) trace(r[x][i],0);
            else trace(r[x][i],1);
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++) {
        scanf("%d",&x);
        r[x].push_back(i);
    }
    f(1);
    printf("%d %d\n",d[1][1],d[0][1]);

    trace(1,1);
    while(!pq.empty()){
        printf("%d ",pq.top()); pq.pop();
    } printf("-1\n");

    trace(1,0);
    while(!pq.empty()){
        printf("%d ",pq.top()); pq.pop();
    } printf("-1");
    return 0;
}
