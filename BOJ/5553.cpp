#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
int n,ans;
p a[300100];
priority_queue<p, vector<p>, greater<p> > pq;
ll hap;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        a[i] = make_pair(x,y);
    }

    sort(a,a+n);
    for(int i=0;i<n;i++){
        hap += a[i].first;
        pq.push(make_pair(a[i].second,a[i].first));
        while(!pq.empty() && hap > pq.top().first*pq.size()){
            hap -= pq.top().second;
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }
    printf("%d",ans);
}