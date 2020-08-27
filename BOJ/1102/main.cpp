#include<bits/stdc++.h>
#define MAX 100000000
using namespace std;

int d[1<<16],a[20][20];
int n,p,dap = MAX;
char c[20];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);

    scanf("%s ",c);
    int s = 0,ang = 0;
    for(int i=0;i<n;i++){
        if(c[i] == 'Y'){
            s+=(1<<i);
            ang++;
        }
    }
    scanf("%d",&p);
    for(int i=0;i<(1<<n);i++) d[i] = MAX;
    d[s] = 0;
    for(int x=1;x<(1<<n);x++){
        for(int i=0;i<n;i++){
            if(x&(1<<i)){
                int from = x^(1<<i);
                if(d[from] >= MAX) continue;
                for(int j=0;j<n;j++)
                    if(from&(1<<j))
                        d[x] = min(d[x],d[from] + a[j][i]);
            }
        }
        if(__builtin_popcount(x)>=p) dap = min(dap,d[x]);
    }
    if(p == 0) printf("0");
    else if(dap >= MAX) printf("-1");
    else printf("%d",dap);

    return 0;
}
