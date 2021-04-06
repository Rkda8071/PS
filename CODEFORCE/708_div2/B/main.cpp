#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,a[100100];
int main(){
    scanf("%d",&t);
    while(t--){
        int dap = 0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<=m;i++) a[i] = 0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            a[x%m]++;
        }
        if(a[0]) dap++;
        for(int i=1;i<m;i++){
            if(i==m-i){
                if(a[i]) dap++;
                a[i] = 0;
                continue;
            }
            int x = min(a[i],a[m-i]);
            if(x){
                a[i] -= x;
                a[m-i] -= x;
                dap++;
                if(max(a[i],a[m-i])>1) dap+=max(a[i],a[m-i]) - 1;
            }else dap+=max(a[i],a[m-i]);
            a[i] = a[m-i] = 0;
        }
        printf("%d\n",dap);
    }
    return 0;
}
