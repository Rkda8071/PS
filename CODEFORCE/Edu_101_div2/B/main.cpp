#include<bits/stdc++.h>
using namespace std;
int t;
int a[110],b[110];
int n,m;
int main(){
    scanf("%d",&t);
    while(t--){
        int ang,dap,nn,mm;
        dap = nn = mm = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        dap = 0;
        for(int i=1;i<=n;i++){
            dap += a[i];
            nn = max(nn,dap);
        }
        dap = 0;
        for(int i=1;i<=m;i++){
            dap += b[i];
            mm = max(mm,dap);
        }
        printf("%d\n",nn+mm);
    }
    return 0;
}
