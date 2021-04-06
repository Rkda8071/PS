#include<bits/stdc++.h>
using namespace std;
int a[100100];
int b[100100];
double d[100100];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,nn;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(nn=n;nn>=1;nn--) if(nn!=a[nn]) break;

        for(int i=1;i<=m;i++)
            scanf("%d %lf",&b[i],&d[i]);
        double ang = 1,dap = 0;

        for(int i=1;i<=m;i++){
            if(b[i]>=nn){
                dap += (ang*d[i]);
                ang = ang*(1-d[i]);
            }
        }
        if(nn==0) printf("1.000000\n");
        else printf("%f\n",dap);
    }
    return 0;
}
