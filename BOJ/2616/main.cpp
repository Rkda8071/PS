#include<bits/stdc++.h>
using namespace std;
int a[50010],d[50010][4];
int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    scanf("%d",&k);
    for(int i=k;i<=n;i++){
        for(int j=1;j<=3;j++){
            d[i][j] = max(d[i-1][j],d[i-k][j-1] + a[i]-a[i-k]);
        }
    }
    printf("%d",d[n][3]);
    return 0;

}
