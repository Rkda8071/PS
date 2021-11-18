#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> ttp;
typedef tuple<int,int> tp;
priority_queue<tp,vector<tp>,greater<tp> > pq;
int d[500]; // °Å¸®
int n,m;
int s,e,k;
vector<tp> w[500];
vector<ttp> a[500];
void init(){
    scanf("%d %d",&s,&e);
    for(int i=0;i<n;i++)
        a[i].clear();
    for(int i=0;i<m;i++){
        int u,v,p;
        scanf("%d %d %d",&u,&v,&p);
        a[u].push_back(ttp(v,p,0));
    }
}
void dij(){
    for(int i=0;i<n;i++)
        d[i] = 2000000000;
    d[s] = 0;
    w[s].clear();
    pq.emplace(0,s);
    while(!pq.empty()){
        int y,x;
        tie(y,x) = pq.top(); pq.pop();
        for(int i=0;i<a[x].size();i++){
            int xx,yy,z;
            tie(xx,yy,z) = a[x][i];
            if(z) continue;
            if(d[xx] > d[x] + yy){
                d[xx] = d[x] + yy;
                w[xx].clear();
                pq.emplace(d[xx],xx);
            }
            if(d[xx] >= d[x] + yy)
                w[xx].push_back(tp(x,i));
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    while(n && m){
        init();
        dij();
        queue<int> q;
        q.push(e);
        while(!q.empty()){
            int x,y,k;
            k = q.front(); q.pop();
            for(auto ww : w[k]){
                tie(x,y) = ww;
                if(get<2>(a[x][y])) continue;
                q.push(x);
                a[x][y] = ttp(get<0>(a[x][y]),get<1>(a[x][y]),1);
            }
        }
        dij();
        printf("%d\n",d[e] == 2000000000 ? -1 : d[e]);
        scanf("%d %d",&n,&m);
    }
}
