#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,dap=0LL;
        scanf("%lld %lld",&a,&b);
        for(ll y=2LL;y<=b;y++){
            ll i = min(y-1LL,a/y);
            if(y*i + i > a) i--;
            dap+=i;
        }
        printf("%lld\n",dap);
    }
    return 0;
    //1<=x<=a && 1<=y<=b
    //x/y == x%y

    //i = x/y
    //y*i + i <= a
}
