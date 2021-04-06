#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll> tp;
int t,n;
ll a,b;
ll ang[100100],ang2[100100];
tp m[100100];
bool f(){
    for(int i=1;i<=n;i++){
        ll aa,bb,cc;
        tie(aa,bb) = m[i]; //Ã¼,µô
        cc = bb/a;
        if(bb%a) cc++;
        b -= cc*aa;
        if(i==n && b+aa>0LL) return true;
        if(b<=0LL) return false;
    }
    return false;
}
int main() {
    scanf("%d",&t);
    while (t--){
        scanf("%lld %lld %d",&a,&b,&n); //µô,Ã¼,Àû
        for(int i=1;i<=n;i++) scanf("%lld",&ang[i]); //µô
        for(int i=1;i<=n;i++) scanf("%lld",&ang2[i]); //Ã¼
        for(int i=1;i<=n;i++) m[i] = tp(ang[i],ang2[i]);
        sort(m+1,m+n+1);
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
