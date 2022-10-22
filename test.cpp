#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A{
    ll m,v;
    bool operator<(const A &r) const{
        return m<r.m || (m==r.m && v<r.v);
    }
    A operator+(const A &r) const{
        return {m+r.m, v+r.v};
    }
}a,b;

int main(){
    a = {3, 5};
    b = {2, 1};

    printf("%d %d\n",b<a, a<b);
    a = a + b;
    printf("%lld %lld",a.m, a.v);
}