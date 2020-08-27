#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll hap;
struct A{
    ll x,y;
}a[10100];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
    for(int i=1;i<n;i++)
        hap += a[i].x*a[i+1].y - a[i+1].x*a[i].y;
    hap += a[n].x*a[1].y - a[1].x*a[n].y;
    hap = abs(hap);
    printf("%.1f",(double)hap/2);
    return 0;
}
