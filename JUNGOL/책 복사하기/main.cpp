#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[510],l,r;
stack<int> s;
int n,m;
bool f(ll x){
    int k = m;
    ll hap = 0;
    for(int i=n;i>=1;i--){
        if(hap+a[i]>x){
            if(--k){
                hap = 0;
            } else{
                return 0;
            }
        }
        hap += a[i];
    }
    return 1;
}
void p(ll x){
    int k = m;
    ll hap = 0;
    for(int i=n;i>=1;i--){
        if(i==k-1){
            --k;
            s.push(i+1); hap=0;
        }
        if(hap+a[i]>x){
            if(--k){
                hap = 0;
                s.push(i+1);
            }
        }
        hap += a[i];
    }
}
int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);
        l = r = 0;
        for(int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            l = max(l,a[i]);
            r += a[i];
        }
        while(l<r){
            if(f((l+r)/2)) r = (l+r)/2;
            else l = (l+r)/2 + 1;
        }
        p(l);
        for(int i=1;i<=n;i++){
            if(!s.empty() && s.top() == i) {printf("/ "); s.pop();}
            printf("%lld ",a[i]);
        }
        puts("");
    }
    return 0;
}
