#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,a[100100],hap;
int n,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %lld",&n,&x);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        hap = 0;
        int i;
        for(i=n;i>=1;i--){
            hap+=a[i]-x;
            if(hap<0) break;
        }
        printf("%d\n",n-i);
    }
    return 0;
}
