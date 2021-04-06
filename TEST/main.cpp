#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll k,m,nn,n,dap=0LL;
    scanf("%lld",&n);

    nn = n;
    if(n%2LL==0){
        while(n%2LL==0){
            dap+=2LL;
            n/=2LL;
            printf("2\n");
        }
    }
    for(ll i=3LL;i*i<=nn;i++){
        if(n%i==0){
            while(n%i==0){
                dap+=i;
                n/=i;
                printf("%lld\n",i);
            }
        }
        if(n==1) break;
    }
    if(n>1) dap+=n;
    printf("%lld",dap);
    return 0;
}
