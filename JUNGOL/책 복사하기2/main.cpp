#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100100],l,r;
stack<int> s;
int n,m;
bool f(ll y){
    int k = m,x = n;
    ll hap = 0;
    while(k--){
        x = lower_bound(a,a+x,a[x]-y) - a;
    }
    if(x==0) return 1;
    return 0;
}
void p(ll x){
    int k = m;
    ll hap = 0;
    for(int i=n;i>=1;i--){
        if(i==k-1){
            --k;
            s.push(i+1); hap=0;
        }
        if(hap+a[i]-a[i-1]>x){
            if(--k){
                hap = 0;
                s.push(i+1);
            }
        }
        hap += a[i]-a[i-1];
    }
}
int main(){
    scanf("%d %d",&n,&m);
    l = r = 0;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        l = max(l,a[i]);
        r += a[i];
        a[i] += a[i-1];
    }
    while(l<r){
        if(f((l+r)/2)) r = (l+r)/2;
        else l = (l+r)/2 + 1;
    }
    p(l);
    for(int i=1;i<=n;i++){
        if(!s.empty() && s.top() == i) {printf("/ "); s.pop();}
        printf("%lld ",a[i]-a[i-1]);
    }
    return 0;
}
