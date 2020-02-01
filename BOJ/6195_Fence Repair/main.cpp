// JUNGOL 1929_책꽂이 만들기
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll> > pq;
ll dap,hap,x,y;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&x);
        pq.push(x);
    }
    while(!pq.empty()){
        x = pq.top(); pq.pop();
        if(pq.empty()) break;
        y = pq.top(); pq.pop();
        dap += x+y;
        pq.push(x+y);
    }
    printf("%lld",dap);
    return 0;
}
