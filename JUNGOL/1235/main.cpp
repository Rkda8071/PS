/*#include<bits/stdc++.h>
using namespace std;
int n,k,dap;
int a[2020],d[2020][2020];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) a[i+n] = a[i];

    for(k=1;k<=n/2;k+=2){
        for(int i=1;i<=n;i++){
            if(i!=n)d[i][i+k] = d[i+1][i+k-1] + ((a[i]==a[i+k])?1:0);
            else d[i][i+k] = d[1][k-1] + ((a[i]==a[i+k])?1:0);
            for(int j=i+1;j<i+k;j++){
                if(j+1<=n) d[i][i+k] = max(d[i][i+k],d[i][j]+d[j+1][i+k]);
                else d[i][i+k] = max(d[i][i+k],d[i][j]+d[j+1-n][i+k-n]);
            }
        }
    }
    k -= 2;
    for(int i=1;i<=n;i++){
        if(i+k+1<=n) dap = max(dap,d[i][i+k]+d[i+k+1][i+n-1]);
        else dap = max(dap,d[i][i+k]+d[i+k+1-n][i-1]);
    }
    printf("%d",dap);
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010],d[1010][1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int k=1;k<=n;k+=2){
        for(int s=1;s<=n-k;s++){
            int e = s+k;
            d[s][e] = d[s+1][e-1] + ((a[s]==a[e])?1:0);
            for(int m=s+1;m<e;m+=2)
                d[s][e] = max(d[s][e],d[s][m] + d[m+1][e]);
        }
    }
    printf("%d",d[1][n]);
    return 0;
}
