#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],hap,dap=1,p;
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]>n-k){
            hap += a[i];
            if(p != 0){
                dap *= (ll)(i-p);
                dap = dap % 998244353;
            }
            p = i;
        }
    }
    printf("%lld %lld",hap,dap);
    return 0;
}
