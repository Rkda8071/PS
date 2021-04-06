#include<bits/stdc++.h>
using namespace std;
int t,n,k,x,chk[100010],cnt,ang;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n); cnt = 0; ang = 0;
        for(int i=0;i<=n;i++) chk[i] = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&k); chk[0] = 0;
            for(int j=0;j<k;j++){
                scanf("%d",&x);
                if(!chk[0] && !chk[x]){
                    chk[0] = chk[x] = 1;
                    ++cnt;
                }
            }
            if(!chk[0] && !ang) ang = i;
        }
        if(cnt<n){
            printf("IMPROVE\n");
            for(int i=1;i<=n;i++){
                if(!chk[i]){
                    printf("%d %d\n",ang,i);
                    break;
                }
            }
        } else printf("OPTIMAL\n");
    }
    return 0;
}
