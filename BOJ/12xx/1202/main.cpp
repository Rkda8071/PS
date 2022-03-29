#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dap;
struct A{
    int m,v;
    bool operator<(const A &r)const{
        return m<r.m || (m==r.m && v<r.v);
    }
}a[300100];
int n,k;
int b[300100];
priority_queue<ll> pq;

void init(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int m,v;
        scanf("%d %d",&m,&v);
        a[i] = {m,v};
    }
    for(int i=0;i<k;i++) scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+k);
}

int main(){
    init();
    int cnt = 0;
    for(int i=0;i<k;i++){
        while(cnt<n && a[cnt].m<=b[i]) pq.push((ll)(a[cnt++].v));
        if(!pq.empty()){dap += pq.top(); pq.pop();}
    }
    printf("%lld",dap);
    return 0;
}
