#include<bits/stdc++.h>
using namespace std;
int t,a[110];
int main(){
    scanf("%d",&t);
    while(t--){
        int n,u,v,chk=0,dap=0;
        scanf("%d %d %d",&n,&u,&v);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++) if(abs(a[i]-a[i+1])>1) {chk=1; break;}
        if(!chk){
            for(int i=2;i<=n;i++) if(a[i]!=a[1]) {chk=2; break;}
            if(!chk)// ´Ù °°À½
                dap = v+min(u,v);
            else
                dap = min(u,v);
        }
        printf("%d\n",dap);
    }
}
