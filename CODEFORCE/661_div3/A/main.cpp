#include<bits/stdc++.h>
using namespace std;
int n,t,a[100];
bool f(){
    a[0] = a[1];
    for(int i=1;i<=n;i++)
        if(a[i]-a[i-1]>1) return false;
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
