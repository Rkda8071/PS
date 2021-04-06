#include<bits/stdc++.h>
using namespace std;
int a[1000],d[1000];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,cnt=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=(n+1)/2;i++){
            d[cnt] = a[i];
            cnt+=2;
        }
        cnt = 2;
        for(int i=n;i>(n+1)/2;i--){
            d[cnt] = a[i];
            cnt+=2;
        }
        for(int i=1;i<=n;i++) printf("%d ",d[i]);
        puts("");
    }
    return 0;
}
