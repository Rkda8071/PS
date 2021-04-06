#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct A{
    ll x,y;
    bool operator<(const A &r)const{
        return x<r.x || (x==r.x && y<r.y);
    }
}a[110];
stack<A> s;
vector<A> dap,d,u;
ll w(A a,A b,A c) { return (c.x-a.x)*(b.y-a.y) - (c.y-a.y)*(b.x-a.x); }
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        a[i] = {x,y};
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i<=2){s.emplace(a[i]); continue;}
        // 일단 추가는 함
        // 그런데 지금 cur보다 오른쪽에 있는 애가 있으면 cur 없애고 a[i] 넣음
        A cur = s.top(); s.pop();
        while(!s.empty() && w(s.top(),cur,a[i]) > 0L){
            cur = s.top(); s.pop();
        }
        s.emplace(cur);
        s.emplace(a[i]);
    }
    while(!s.empty()){
        d.push_back(s.top()); s.pop();
    }

    for(int i=1;i<=n;i++){
        if(i<=2){s.emplace(a[i]); continue;}
         A cur = s.top(); s.pop();
        while(!s.empty() && w(s.top(),cur,a[i]) < 0L){
            cur = s.top(); s.pop();
        }
        s.emplace(cur);
        s.emplace(a[i]);
    }
    while(!s.empty()){
        u.push_back(s.top()); s.pop();
    }
    for(int i=d.size()-1;i>=0;i--) dap.push_back(d[i]);
    for(int i=1;i<u.size()-1;i++) dap.push_back(u[i]);

    ll hap = 0LL;
    for(int i=0;i<dap.size()-1;i++)
        hap += dap[i].x*dap[i+1].y - dap[i+1].x*dap[i].y;
    hap += dap[dap.size()-1].x*dap[0].y - dap[0].x*dap[dap.size()-1].y;
    hap = abs(hap);
    double ang = ((double)hap)/2;
    if((ll)ang == ang){
        printf("%lld",hap/2);
    }else{
        printf("%.1f",((double)hap)/2);
    }
    return 0;
}
