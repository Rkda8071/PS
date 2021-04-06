#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200100];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n*2+1;i++) a[i] = 0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        int dap=0;
        for(int i=1;i<=n*2+1;i++){
            if(a[i]>=2) a[i+1]++;
            if(a[i]) dap++;
        }
        printf("%d\n",dap);
    }
    return 0;
}
