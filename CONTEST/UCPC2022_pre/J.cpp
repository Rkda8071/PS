#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> p;
ll a[500010],mod = 1000000000LL;
p b[500010];
bool chk[500010],ans = true;
int n;
struct A{
    ll a[5] = {0LL};
    A operator*(const A &r) const{
        A tmp;
        for(int i=0;i<5;i++) tmp.a[i] = 0LL;
        for(int i=0;i<5;i++){
            if(i!=0) tmp.a[i] = a[i]*r.a[i] + ((a[i-1]*r.a[i-1]) / mod);
            else tmp.a[i] = a[i]*r.a[i];
            tmp.a[i] = tmp.a[i]%mod;
        }

        return tmp;
    }
    bool operator == (const A &r) const{
        for(int i=0;i<5;i++)
            if(a[i] != r.a[i]) return false;
        return true;
    }
    bool operator < (const A &r) const{
        for(int i=4;i>=0;i--){
            if(a[i] < r.a[i]) return true;
            if(a[i] > r.a[i]) return false;
        }
        return false;
    }
} ang;
bool solve(A x, A y){
    A tmp2, tmp = x*y;
    for(int i=0;i<5;i++) tmp2.a[i] = 0LL;
    ll mid, l = 1LL,r = 1e18;
    while(l<=r){
        mid = (l+r)/2LL;
        tmp2.a[2] = tmp2.a[3] = tmp2.a[4] = 0LL;
        
        tmp2.a[1] = mid/mod;
        tmp2.a[0] = mid%mod;
        tmp2 = tmp2*tmp2;

        //printf("[%lld %lld %lld]\n\n",l,mid,r);
        
        //printf("[%lld %lld %lld %lld]\n",tmp2.a[0], tmp2.a[1], tmp2.a[2], tmp2.a[3], tmp2.a[4]);
        //printf("[%lld %lld %lld %lld]\n\n",tmp.a[0], tmp.a[1], tmp.a[2], tmp.a[3], tmp.a[4]);

        if(tmp == tmp2){
            return true;
        }else if(tmp < tmp2){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    //printf("[%lld] %lld %lld\n",tmp.a[0], l,r);
    return false;
}

void dfs(int x){
    if(chk[x]){
        ang.a[1] = b[x].first/mod;
        ang.a[0] = b[x].first%mod;
        return;
    }
    chk[x] = 1;
    dfs(b[x].second);

    if(!ans) return;
    A tmp;
    tmp.a[1] = b[x].first/mod;
    tmp.a[0] = b[x].first%mod;
    ans = solve(tmp,ang);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        b[i] = p(a[i], i);
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        if(b[i].second != i && !chk[i]){
            dfs(i);
        }
    }
    if(ans) printf("YES");
    else printf("NO");
}