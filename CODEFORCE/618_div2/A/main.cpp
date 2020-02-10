#include<bits/stdc++.h>
using namespace std;
int a[110],cnt,hap;
int main(){
    int t;
    int n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        hap = cnt = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==0) ++cnt;
            hap += a[i];
        }
        if(cnt + hap == 0) printf("%d\n",cnt + 1);
        else printf("%d\n",cnt);
    }
}
