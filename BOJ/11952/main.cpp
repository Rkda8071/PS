#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> p;
int c[100100];
vector<int> a[100100];
queue<int> q;
ll d[100100];
priority_queue<p, vector<p>,greater<p> > pq;
int main(){
    int n,m,k,s;
    ll pp,qq;
    int x,y;
    scanf("%d %d %d %d",&n,&m,&k,&s);
    scanf("%lld %lld",&pp,&qq);
    for(int i=1;i<=n;i++) d[i] = 20000000000000000;
    for(int i=1;i<=k;i++) {
        scanf("%d",&x);
        c[x] = 1; q.push(x);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    while(!q.empty()){
        x = q.front(); q.pop();
        for(int i=0;i<a[x].size();i++){
            if(c[a[x][i]]==0){
                c[a[x][i]] = c[x]+1;
                if(c[x]<s) q.push(a[x][i]);
            }
        }
    }
    pq.push(make_pair(0,1));
    d[1] = 0;
    while(!pq.empty()){
        ll xx = pq.top().first;
        y = pq.top().second;
        pq.pop();
        if(d[y]<xx) continue;
        for(int i=0;i<a[y].size();i++){
            int ang = (c[a[y][i]] == 0) ? pp : qq;
            if(d[a[y][i]]>xx+ang && c[a[y][i]] != 1){
                d[a[y][i]] = xx + ang;
                pq.push(make_pair(xx+ang,a[y][i]));
            }
        }
    }
    printf("%lld",d[n] - ((c[n] == 0) ? pp : qq));
    return 0;
}
