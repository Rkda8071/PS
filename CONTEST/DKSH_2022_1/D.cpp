#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p[100010],s[100010];
ll a[100010],ans;
pair<ll, int> ang[100010];
vector<int> v[100010];
int fin(int x){
    if(p[x] == x) return x;
    return p[x] = fin(p[x]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ang[i] = make_pair(-a[i],i);
    }
    sort(ang+1,ang+n+1);
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        int x = ang[i].second;
        p[x] = x;
        s[x] = 1;
        
        for(int y : v[x]){
            if(!p[y]) continue;
            y = fin(y);
            s[x] += s[y];
            p[y] = x;
        }
        ans = max(ans, a[x]*(ll)s[x]);
    }
    printf("%lld",ans);
}