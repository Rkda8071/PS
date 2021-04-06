#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a,b;
int ff(ll c){
    ll d = c;
    if(c==1LL) return 2000000000;
    int ang = 1;
    while(d<=a){
        d*=c;
        ang++;
    }
    return ang;
}
int f(){
    int cnt=0,dap = 2000000000;
    if(b>a) return 1;
    if(b*b>a) return 2;
    for(;b*b<=a+1LL || dap==2000000000;b++){
        dap = min(dap,cnt+ff(b));
        cnt++;
    }
    return dap;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&a,&b);
        printf("%d\n",f());
    }
    return 0;
}
