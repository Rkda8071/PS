#include<bits/stdc++.h>
using namespace std;
int t,n,a[200100];
int f(){
    int l,r,ang=1;
    for(l=1;l<=n;l++) if(a[l] != l) break;
    for(r=n;r>=1;r--) if(a[r] != r) break;

    if(r<l) return 0;
    for(int i=l;i<=r;i++) if(a[i] == i) return 2;
    return 1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf("%d\n",f());
    }
    return 0;
}
