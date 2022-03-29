#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010],d[1010][1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int k=1;k<n;k++){
        for(int s=1;s<=n-k;s++){
            int e = s+k;
            d[s][e] = d[s+1][e-1] + ((a[s]==a[e])?1:0);
            for(int m=s;m<e;m++)
                d[s][e] = max(d[s][e],d[s][m] + d[m+1][e]);
        }
    }
    printf("%d",d[1][n]);
    return 0;
}
