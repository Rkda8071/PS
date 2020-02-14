#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int n,t,dap,maxim,mini,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        maxim = 0; mini = 2000000000; a[0] = -1; dap = -1;
        for(int i=2;i<=n;i++) if(a[i]>=0 && a[i-1]>=0) dap = max(dap,abs(a[i]-a[i-1]));
        for(int i=1;i<=n;i++){
            if(a[i] == -1){
                if(a[i-1] != -1 && i!=1) {
                    mini = min(a[i-1],mini);
                    maxim = max(a[i-1],maxim);
                } if(a[i+1] != -1 && i!=n){
                    mini = min(a[i+1],mini);
                    maxim = max(a[i+1],maxim);
                }
            }
        }
        if(mini == 2000000000 && maxim == 0){
            if(dap == -1) printf("0 0\n");//k = 0; dap = 0;
            else printf("%d 0\n",dap);
            continue;
        }
        else k = (mini+maxim)/2;
        if(dap!=-1) dap = max(max(mini-k,maxim-k),dap);
        else dap = max(mini-k,maxim-k);
        printf("%d %d\n",dap,k);
    }
    return 0;
}
