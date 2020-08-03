#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[3010],d[3010];
ll w,h; // Æ®·°, Çï¸®ÄßÅÍ
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%lld %lld",&w,&h);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i] = d[i-1] + min(a[i]*w,h);
    bool ang;
    for(int e=1;e<=n;e++){
        for(int p=e;p>=1;p--){
            ll chk = a[p],cur = h;
            ang = false;
            for(int i=p+1;i<=e;i++){
                if((a[i]-chk)*w > h) {ang = true; break;}
                cur += (a[i] - chk)*w;
            }
            if(ang) continue;
            for(int s=p;s>=1;s--){
                if((chk - a[s])*w > h) {ang = true; break;}
                cur += (chk - a[s])*w;
                d[e] = min(d[e],d[s-1] + cur);
            }
        }
    }
    printf("%lld",d[n]);
    return 0;
}
