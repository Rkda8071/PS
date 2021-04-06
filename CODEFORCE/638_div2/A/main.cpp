#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int n;
        ll hap = 0LL;
        scanf("%d",&n);
        hap = (1LL<<n);
        for(int i=n-1;i>=n/2;i--){
            hap -= (1LL<<i);
        }
        for(int i=1;i<n/2;i++){
            hap += (1LL<<i);
        }
        printf("%lld\n",hap);
    }
    return 0;
}
