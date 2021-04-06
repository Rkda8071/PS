#include<bits/stdc++.h>
using namespace std;
int t;
int a[110];
int main(){
    scanf("%d",&t);
    while(t--){
        int n,d;
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(a[n]<=d || a[1]+a[2]<=d) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
