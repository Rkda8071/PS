#include<bits/stdc++.h>
using namespace std;
int a[410],b[410],d[410][410];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i-a[0]]);
        if(a[i-a[0]]==0) a[0]++;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i-b[0]]);
        if(b[i-b[0]]==0) b[0]++;
    }
    for(int i=1;i<=n-a[0];i++){
        //d[i][0] = d[i-1][0] + a[i]*b[i];
        for(int j=i;j<=n-b[0];j++){
            d[i][j-i] = d[i-1][j-i-1];
        }
    }
    for(int i=1;i<=n-a[0];i++){

    }
    return 0;
}
