#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000];
priority_queue<ll,vector<ll>,greater<ll> > pq;
int main(){
    int n = 0;
    pq.push(1);
    while(n<=1500){
        a[++n] = pq.top(); pq.pop();
        if(a[n]%3 && a[n]%5) pq.push(a[n]*2);
        if(a[n]%5) pq.push(a[n]*3);
        pq.push(a[n]*5);
    }
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        printf("%d\n",a[n]);
    }
    return 0;
}
