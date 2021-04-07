#include<bits/stdc++.h>
using namespace std;
int t,n,w;
int a[20100],d[3][20100];
int f(int x){
    if(x<=w) return 1;
    return 2;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&w);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=n+1;i<=n*2;i++) scanf("%d",&a[i]);

        if(n==1){
            printf("%d\n",f(a[1]+a[2]));
            continue;
        }

        int dap = 0;
        memset(d,1,sizeof(d));
        d[1][1] = d[2][1] = 1;
        d[0][1] = 0;
        for(int i=1;i<n;i++){
            d[0][i+1] = min(d[0][i+1],min(d[0][i]+f(a[i]+a[i+n]),min(d[1][i],d[2][i])+1));
            d[0][i+2] = d[0][i] + f(a[i]+a[i+1]) + f(a[i+n]+a[i+n+1]);
            d[1][i+1] = min(d[0][i+1]+1,min(d[0][i]+1,d[2][i])+f(a[i]+a[i+1]));
            d[2][i+1] = min(d[0][i+1]+1,min(d[0][i]+1,d[1][i])+f(a[i+n]+a[i+n+1]));
        }
        dap = min(d[0][n]+f(a[n]+a[n*2]),min(d[1][n],d[2][n])+1);

        if(a[n]+a[1] <= w){ //d[1][1] == 1
            memset(d,1,sizeof(d));
            d[1][1] = d[2][1] = 1;
            d[0][1] = 0;

            for(int i=1;i<n;i++){
                if(i!=1) d[0][i+1] = min(d[0][i+1],min(d[0][i]+f(a[i]+a[i+n]),min(d[1][i],d[2][i])+1));
                else d[0][i+1] = 2;
                if(i!=1) d[0][i+2] = d[0][i] + f(a[i]+a[i+1]) + f(a[i+n]+a[i+n+1]);
                if(i!=1) d[1][i+1] = min(d[0][i+1]+1,min(d[0][i]+1,d[2][i])+f(a[i]+a[i+1]));
                else d[1][i+1] = d[0][i+1]+1;
                d[2][i+1] = min(d[0][i+1]+1,min(d[0][i]+1,d[1][i])+f(a[i+n]+a[i+n+1]));
            }
            dap = min(dap,min(d[0][n]+1,d[2][n]));
        }
        if(a[n+n]+a[n+1] <= w){
            memset(d,1,sizeof(d));
            d[1][1] = d[2][1] = 1;
            d[0][1] = 0;
            for(int i=1;i<n;i++){
                if(i!=1) d[0][i+1] = min(d[0][i+1],min(d[0][i]+f(a[i]+a[i+n]),min(d[1][i],d[2][i])+1));
                else d[0][i+1] = 2;
                if(i!=1) d[0][i+2] = d[0][i] + f(a[i]+a[i+1]) + f(a[i+n]+a[i+n+1]);
                d[1][i+1] = min(d[0][i+1]+1,min(d[0][i]+1,d[2][i])+f(a[i]+a[i+1]));
                if(i!=1) d[2][i+1] = min(d[0][i+1]+1,min(d[0][i]+1,d[1][i])+f(a[i+n]+a[i+n+1]));
                else d[2][i+1] = d[0][i+1]+1;
            }
            dap = min(dap,min(d[0][n]+1,d[1][n]));
        }
        if(a[n]+a[1]<=w && a[n+n]+a[n+1]<=w){
            memset(d,1,sizeof(d));
            d[2][1] = d[1][1] = 1;
            d[0][1] = 0;
            for(int i=1;i<n;i++){
                if(i!=1) d[0][i+1] = min(d[0][i+1],min(d[0][i]+f(a[i]+a[i+n]),min(d[1][i],d[2][i])+1));
                else d[0][i+1] = 2;
                if(i!=1) d[0][i+2] = d[0][i] + f(a[i]+a[i+1]) + f(a[i+n]+a[i+n+1]);
                if(i!=1) d[1][i+1] = min(d[0][i+1]+1,min(d[0][i]+1,d[2][i])+f(a[i]+a[i+1]));
                else d[1][i+1] = d[0][i+1]+1;
                if(i!=1) d[2][i+1] = min(d[0][i+1]+1,min(d[0][i]+1,d[1][i])+f(a[i+n]+a[i+n+1]));
                else d[2][i+1] = d[0][i+1]+1;
            }
            dap = min(d[0][n],dap);
        }
        printf("%d\n",dap);
    }
}
/*
1
3 5
3 2 2
1 4 2
*/
