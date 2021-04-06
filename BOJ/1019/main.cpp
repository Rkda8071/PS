#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10],d[11][11];
void f(ll x,ll y){
    //printf("%d %d",x,y);
    for(ll i=x/y-1;i>0;i--){

    }
}
int main(){
    ll n,ang = 1;
    scanf("%lld",&n);
    for(int i=0;i<10;i++) d[1][i] = 1;
    for(int i=2;i<10;i++){
        if(ang*10>n) break;
        ang*=10;
        for(int j=0;j<10;j++) d[i][j] = ang + d[i-1][j];
    }
    f(n,ang);
    return 0;
}
