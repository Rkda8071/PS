#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A{
    ll mini,maxim;
    ll lm, mr;
    ll lmr;
}seg[1050000];
ll n,nn,q;

A f(A l, A r){
    return{
        min(l.mini, r.mini),
        max(l.maxim, r.maxim),
        max(r.maxim - l.mini,max(l.lm, r.lm)),
        max(l.maxim - r.mini,max(l.mr, r.mr)),
        max(max(l.lm - r.mini, r.mr - l.mini),max(l.lmr, r.lmr))
    };
}

void init(){
    scanf("%lld %lld",&n,&q);
    for(nn=1LL;nn<n;nn*=2LL);
    for(ll i = nn, x; i < nn + n; i++){
        scanf("%lld",&x);
        seg[i] = {x,x,-2000000000LL,-2000000000LL,-2000000000LL};
    }
    for(ll i = nn + n; i < nn*2; i++)
        seg[i] = {2000000000LL, -2000000000LL, -2000000000LL, -2000000000LL, -2000000000LL};
    for(ll i = nn - 1LL; i>0LL; i--){
        seg[i] = f(seg[i*2],seg[i*2+1]);
    }
}

A fin(ll id, ll x, ll y, ll l, ll r){
    if(r < x || y < l) return {2000000000LL, -2000000000LL, -2000000000LL, -2000000000LL, -2000000000LL};
    if(x <= l && r <= y) return seg[id];
    return f(fin(id*2LL,x,y,l,(l+r)/2LL), fin(id*2LL + 1LL,x,y,(l+r)/2LL + 1LL, r));
}

int main(){
    init();
    while(q--){
        ll x,y,z;
        scanf("%lld %lld %lld",&x,&y,&z);
        if(x==1LL){ // y번의 학생의 매력을 z로
            y = y + nn - 1;
            seg[y].mini = seg[y].maxim = z;
            while(y/=2LL)
                seg[y] = f(seg[y*2],seg[y*2+1]);
            
        }else{ // y부터 z사이의 세 학생이 공연함
            printf("%lld\n",fin(1LL,y,z,1,nn).lmr);
        }
    }
}