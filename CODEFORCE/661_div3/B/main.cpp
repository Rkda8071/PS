#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a[100],b[100],m1,m2;
int main(){
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ll dap = 0LL;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        m1 = a[1];
        for(int i=2;i<=n;i++) m1 = min(m1,a[i]);

        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        m2 = b[1];
        for(int i=2;i<=n;i++) m2 = min(m2,b[i]);

        for(int i=1;i<=n;i++) dap+=max(a[i]-m1,b[i]-m2);
        printf("%lld\n",dap);
    }
    return 0;
}
