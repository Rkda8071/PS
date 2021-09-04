#include<bits/stdc++.h>
using namespace std;
// k일 공부 -> 수상
// 공부할 내용 n개
// 최소 내용 L
typedef long long ll;
ll n,m,l,k;
ll t[100100],d[100100],cnt[100100];
vector<ll> a[100100];
queue<ll> q;
int main(){
    scanf("%lld %lld %lld %lld",&n,&m,&l,&k);
    for(ll i=1LL;i<=n;i++)
        scanf("%lld",&t[i]);
    for(ll i=1LL;i<=m;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y); //y를 하려면 x를 해야함
        cnt[y]++; a[x].push_back(y);
    }

    for(ll i=1LL;i<=n;i++)
        if(cnt[i] == 0LL)
            q.push(i);



    while(!q.empty()){
        ll x,y;
        x = q.front(); q.pop(); // 현재 내용
        d[x] += t[x]; // x내용을 공부한 후의 시간
        if(x==l) break; // L 공부 완료!
        for(auto i=a[x].begin(); i!=a[x].end(); i++){
            y = *i;
            d[y] = max(d[y],d[x]);
            if(--cnt[y] == 0LL)
                q.push(y);
        }
    }
    if(0LL<d[l] && d[l]<=k) printf("%lld",d[l]);
    else printf("Give Up :(");
    return 0;
}
