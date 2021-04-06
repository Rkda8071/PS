#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll x,y,a,b;
        ll dap;
        scanf("%lld %lld %lld %lld",&x,&y,&a,&b);
        dap = min(x,y)*b+(max(x,y)-min(x,y))*a;
        dap = min(dap,(x+y)*a);
        printf("%lld\n",dap);
    }
}
