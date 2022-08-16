#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> p;
int n,m,s,e;
ll d[50010],dx[50010];
vector<p> a[50010];
priority_queue<p, vector<p>, greater<p> > pq;

void solve(int x,ll y){
    for(p t : a[x]){
        int xx = t.first;
        ll yy = t.second;
        if(d[x] > yy || d[xx] <= yy) continue;
        if(dx[xx] != (1LL<<62)) solve(xx,yy);
        d[xx] = yy;
        dx[xx] = min(dx[xx], d[x] + yy);
    }
}

void init(){
    scanf("%d %d",&n,&m);
    for(int x,y,i=0;i<m;i++){
        ll z;
        scanf("%d %d %lld",&x,&y,&z);
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=n;i++) d[i] = dx[i] = (1LL<<62);
    scanf("%d %d",&s,&e);
    dx[s] = d[s] = 0LL; 
    pq.push(make_pair(0,s));
}
int main(){
    init();
    while(!pq.empty()){
        int x = pq.top().second;
        ll y = pq.top().first; pq.pop();
        if(d[x] < y) continue;
        for(p t : a[x]){
            int xx = t.first;
            ll yy = t.second;
            if(d[x] > yy || d[xx] <= yy) continue;
            if(dx[xx] != (1LL<<62)) solve(xx,yy);
        
            d[xx] = yy;
            dx[xx] = min(dx[xx], d[x] + yy);

            pq.push(make_pair(yy,xx));
        }
    }
    if(dx[e]!= (1LL<<62))  printf("%lld",dx[e]);
    else printf("DIGESTA");
}