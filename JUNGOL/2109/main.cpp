#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,m,e;
vector<tp> a[1010],b[1010];
int d[1010],d2[1010];
priority_queue<tp,vector<tp>,greater<tp> > pq;
void in(){
    scanf("%d %d %d",&n,&m,&e);
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(make_tuple(y,z)); // 어디로, 얼마나
        b[y].push_back(make_tuple(x,z)); // y로 누가 올 수 있냐
    }
}
void go(){
    for(int i=1;i<=n;i++) d[i] = 2000000000;
    pq.emplace(0,e); d[e] = 0;
    while(!pq.empty()){
        int y,x; tie(y,x) = pq.top(); pq.pop();
        if(y != d[x]) continue;
        for(int i=0;i<a[x].size();i++){
            int yy,xx; tie(xx,yy) = a[x][i];
            if(d[xx]>y+yy){
                d[xx] = y+yy;
                pq.emplace(y+yy,xx);
            }
        }
    }
}
void bye(){
    for(int i=1;i<=n;i++) d2[i] = 2000000000;
    pq.emplace(0,e); d2[e] = 0;
    while(!pq.empty()){
        int y,x; tie(y,x) = pq.top(); pq.pop();
        if(y != d2[x]) continue;
        for(int i=0;i<b[x].size();i++){
            int yy,xx; tie(xx,yy) = b[x][i];
            if(d2[xx]>y+yy){
                d2[xx] = y+yy;
                pq.emplace(y+yy,xx);
            }
        }
    }
}
int main(){
    in();
    go(); bye();
    int maxim = 0;
    for(int i=1;i<=n;i++) maxim = max(maxim,d[i]+d2[i]);
    printf("%d",maxim);
    return 0;
}
