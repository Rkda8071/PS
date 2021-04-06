#include<bits/stdc++.h>
using namespace std;
int a[200010],cnt[200010];
int t,n,d,m;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) cnt[i] = 0;
        d=m=0;
        for(int i=1;i<=n;i++){
            if(++cnt[a[i]]==1) d++;
            m = max(m,cnt[a[i]]);
        }
        //if(n==1) printf("0\n");
        printf("%d\n",min(n/2,max(min(d,m-1),min(d-1,m))));
    }
    return 0;
}
