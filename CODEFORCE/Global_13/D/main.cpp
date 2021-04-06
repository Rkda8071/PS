// 왜 틀리는지 모르겠음
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll a,b;
bool f(ll x){
    while(x<b){
        if(((b-x)&x) == 0LL) break;
        x += ((b-x)&x);
    }
    return b==x;
}
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%lld %lld",&a,&b);
        if(f(a)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
// 맞는 코드
/*#include<bits/stdc++.h>
using namespace std;
int q;
int a,b;
int n,m;
int aa[40],bb[40];
bool f(){
    int nn,mm;
    nn = mm = 0;
    if(a>b) return 0;
    while(a){
        aa[++n] = a%2;
        a/=2;
    }
    while(b){
        bb[++m] = b%2;
        b/=2;
    }
    for(int i=1;i<=max(n,m);i++){
        nn += aa[i];
        mm += bb[i];
        if(mm>nn) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        for(int i=1;i<=31;i++) aa[i]=bb[i]=0;
        n=m=0;
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
*/
