#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200100];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        ll sw = a[1],m = a[1], hap = 0LL;
        for(int i=1;i<=n;i++){
            if(sw * a[i] > 0LL){
                m = max(m,a[i]);
            } else{
                hap += m;
                sw = a[i];
                m = a[i];
            }
        }
        printf("%lld\n",m+hap);
    }
    return 0;
}
