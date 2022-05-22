#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ang = a[1] + 1, i;
        for(i=2;i<=n;i++){
            ang++;
            if(abs(a[i]-ang)>1) break;
        }
        if(i == n+1) printf("YES\n");
        else printf("NO\n");
    }
}