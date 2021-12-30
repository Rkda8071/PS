#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[10],k;
vector<int> v[1<<10][200];
vector<ll> s;
void f(int x,int chk,int hap,int cur){
    if(x == 5){
        v[chk][hap].push_back(cur);
        return;
    }
    f(x+1,chk,hap,cur*10);
    for(int i=0;i<n;i++){
        if(chk & (1<<i)) continue;
        f(x+1,chk|(1<<i),hap+a[i]*(x+1),cur*10+a[i]);
    }
}
void g(int x,int chk,int hap,ll cur){
    if(x == 5){
        for(int i=0;i<(1<<9);i++){
            if(chk&i) continue;
            for(int ang : v[i][hap]){
                s.push_back(cur*100000LL + (ll)(ang));
            }
        }
        return;
    }
    g(x+1,chk,hap,cur/10LL);
    for(int i=0;i<n;i++){
        if(chk & (1<<i)) continue;
        g(x+1,chk|(1<<i),hap+a[i]*(x+1),cur/10LL+(ll)(a[i]*10000));
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    f(0,0,0,0);
    g(0,0,0,0LL);
    scanf("%d",&k);
    k = min(k,(int)s.size()-1);
    sort(s.begin(),s.end());
    printf("%lld",s[k]);
}
