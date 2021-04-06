#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;
ll f(){
    int cc = 0;
    int chk[20] = {0};
    for(;;n++){
        ++cc;
        ll ang = n;
        while(ang){
            chk[ang%(10LL)]=cc;
            ang/=10LL;
        }
        int book = 0;
        for(int i=1;i<=9;i++){
            if(chk[i]==cc){
                if(n%i){
                    book = 1;
                    break;
                }
            }
        }
        if(book == 0) return n;
    }
    return 0LL;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",f());
    }
    return 0;
}
