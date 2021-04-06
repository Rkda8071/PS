#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,n,t,a[110],chk[110],ang;
int f(int i){
    for(int j=1;j<=n;j++){
        if(!chk[j] && a[i]+a[j]==s) return j;
    }
    return 0;
}
int main(){
    scanf("%d",&t);
    do{
        int k=0,dap=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(s=2;s<=a[n]+a[n-1];s++){
            dap = 0;
            for(int i=1;i<=n;i++) chk[i] = 0;

            for(int i=1;i<=n;i++){
                if(chk[i]) continue;
                chk[i] = 1;
                int ang = f(i);
                if(ang){
                    dap++;
                    chk[ang] = 1;
                }
                else chk[i] = 0;
            }
            k = max(k,dap);
        }
        printf("%d\n",k);
    }while(--t);
    return 0;
}
