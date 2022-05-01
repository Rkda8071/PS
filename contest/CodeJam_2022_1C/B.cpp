#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k;

int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d %d",&n,&k);
        ll l,r,x;
        l = r = 0LL;
        for(int i=0;i<n;i++){
            scanf("%lld",&x);
            l += x;
            r += x*x;
        }
        printf("Case #%d: ",tt);
        
        
    }
}