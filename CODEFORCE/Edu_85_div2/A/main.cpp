#include<bits/stdc++.h>
using namespace std;
int t,n,x,y;
int a[110],b[110];
bool f(){
    for(int i=1;i<=n;i++){
        if(a[i]<b[i] || a[i]<0 || b[i]<0) return false;
    }
    for(int i=2;i<=n;i++){
        if(b[i]-b[i-1]>a[i]-a[i-1]) return false;
        if(a[i-1]>a[i] || b[i-1]>b[i]) return false;
    }
    return true;
}
int main(){
    bool dap;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        dap = true;
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i],&b[i]);
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
