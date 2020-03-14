/*#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010][1010],d1[1010][1010],d2[1010][1010];
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            d1[i][j] = -1000000000;
            d2[i][j] = -1000000000;
        }
    for(int j=1;j<=n;j++) d1[1][j] = a[1][j] + d1[1][j-1];
}
int main(){
    init();
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            d1[i][j] = max(d1[i-1][j],d2[i-1][j]);
            if(j!=1) d1[i][j] = max(d1[i][j],d1[i][j-1]);
            d1[i][j] += a[i][j];
        }
        for(int j=n;j>=1;j--){
            d2[i][j] = max(d1[i-1][j],d2[i-1][j]);
            if(j!=n) d2[i][j] = max(d2[i][j],d2[i][j+1]);
            d2[i][j] += a[i][j];
        }
    }
    printf("%d",max(d1[n][n],d2[n][n]));
    return 0;
}*/

// BOJ 2169
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010][1010],d1[1010][1010],d2[1010][1010];
void init(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            d1[i][j] = -1000000000;
            d2[i][j] = -1000000000;
        }
    for(int j=1;j<=m;j++) d1[1][j] = a[1][j] + d1[1][j-1];
}
int main(){
    init();
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            d1[i][j] = max(d1[i-1][j],d2[i-1][j]);
            if(j!=1) d1[i][j] = max(d1[i][j],d1[i][j-1]);
            d1[i][j] += a[i][j];
        }
        for(int j=m;j>=1;j--){
            d2[i][j] = max(d1[i-1][j],d2[i-1][j]);
            if(j!=m) d2[i][j] = max(d2[i][j],d2[i][j+1]);
            d2[i][j] += a[i][j];
        }
    }
    printf("%d",max(d1[n][m],d2[n][m]));
    return 0;
}

