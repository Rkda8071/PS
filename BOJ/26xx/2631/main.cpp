#include<bits/stdc++.h>
using namespace std;
int a[201],d[201];

int main(){
    int n,lev=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int i=1;i<=n;i++){
        int x = lower_bound(d+1,d+lev,a[i]) - d;
        if(x == lev) ++lev;
        d[x] = a[i];
    }
    printf("%d",n-lev+1);
}
