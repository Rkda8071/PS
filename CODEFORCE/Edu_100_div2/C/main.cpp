#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int test;
int n;
ll t[100100],x[100100];
int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld %lld",&t[i],&x[i]);
        t[n+1] = 2000000000LL;
        ll tt,pre,tar,dap;
        tt = dap = tar = pre = 0LL;
        for(int i=1;i<=n;i++){
            if(abs(tar - pre) + tt <= t[i]){
                if(tt==t[i-1] && tt) dap++;
                pre = tar;
                tar = x[i];
                tt = t[i];
                if(i==n) dap++;
            }else{
                if(tar>=pre && pre+(t[i]-tt)<=x[i]
                   && x[i]<=min(pre+(t[i+1]-tt),tar)) dap++;

                if(tar<=pre && max(tar,(pre-(t[i+1]-tt)))<=x[i]
                   && x[i]<=(pre-(t[i]-tt))) dap++;
            }
        }
        printf("%lld\n",dap);
    }
    return 0;
}
