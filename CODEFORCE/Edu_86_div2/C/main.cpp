#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int a,b,q;
ll l,r;
ll chk[40010];
ll f(int x) {return (((x%a)%b)==((x%b)%a)) ? 0LL : 1LL;}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&q);
        for(int i=1;i<=a*b;i++){
            chk[i] = chk[i-1] + f(i);
        }
        ll m = (ll)(a*b);
        while(q--){
            scanf("%lld %lld",&l,&r);
            if(r/m == l/m)
                printf("%lld ",chk[r%m]-chk[max(0LL,l%m-1LL)]);
            else{
                printf("%lld ",chk[m]-chk[max(0LL,l%m-1LL)] + (chk[m]*(r/m-l/m-1)) + chk[r%m]);
            }
        }
        puts("");
    }
    return 0;
}
