#include<bits/stdc++.h>
using namespace std;
int a[2010],hap[2010];
int main(){
    int n,maxim = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) hap[i] = hap[i-1] + a[i];
    for(int l=1;l<n;l++){
        for(int m=l;m<n;m++){
            //범위 m+1 ~ n에서  hap[m]-hap[l-1]과 값이 같은놈
            int tar = 2*hap[m]-hap[l-1];
            int x = lower_bound(hap+m+1,hap+n+1, tar) - hap;
            if(hap[x] == tar) maxim = max(maxim,tar - hap[m]);
        }
    }
    printf("%d",maxim);
}
