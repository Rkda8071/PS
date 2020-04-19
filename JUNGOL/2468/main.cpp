#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,mini,maxim;
int a[100];
ll f(int x,int y){
    ll cnt=0LL,ang=0LL;
    for(int i=0;i<=x;i++){
        if(a[i]){
            ang -= (1LL<<i);
            ++cnt;
        }
    }
    if(y==1) // ÃÖ¼Ò
        ang += (1LL<<cnt)-1;
    else
        ang += (1LL<<(x+1)) - (1LL<<(x-cnt+1));

    return ang;
}
int main(){
    scanf("%lld",&n);
    for(int i=0;i<=60;i++)
        if(n&(1LL<<i)) a[i] = 1;
    for(int i=0;i<=60;i++){
        if(maxim && mini) break;
        if(!maxim && a[i] && !a[i+1]){
            maxim = n + (1LL<<i) + f(i-1,1);
        }
        if(!mini && i>0 && a[i] && !a[i-1]){
            mini = n - (1LL<<(i-1)) + f(i-2,0);
        }
    }
    printf("%lld %lld",mini,maxim);
    return 0;
}
