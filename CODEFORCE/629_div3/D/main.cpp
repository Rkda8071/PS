#include<bits/stdc++.h>
using namespace std;
int a[200010],chk[200010];
int main(){
    int t,cnt,ang,n;
    scanf("%d",&t); ++t;
    while(--t){
        ang = 0; cnt = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[n+1] = a[1];
        for(int i=1;i<=n;i++){
            if(chk[a[i]] != t){
                cnt++;
                chk[a[i]] = t;
            }
        }
        if(cnt == 1){
            printf("1\n");
            for(int i=1;i<=n;i++) printf("1 ");
        }
        else if(n%2==0){
            printf("2\n");
            for(int i=1;i<=n;i++) printf("%d ",1+(i%2));
        }
        else{
            for(int i=2;i<=n;i++){
                if(a[i]==a[i-1]){
                    ang = 1;
                    break;
                }
            }
            if(ang || a[1] == a[n]) printf("2\n");
            else printf("3\n");
            ang = 0;
            if(a[1] == a[n]){
                for(int i=1;i<n;i++){
                    printf("%d ",1+(i%2));
                } printf("2");
            } else{
                for(int i=1;i<=n;i++){
                    if(!ang && a[i]==a[i-1]){
                        ang = 1;
                    }
                    if(i==n){
                        if(!ang) printf("3 ");
                        else printf("%d ",1+((i+ang)%2));
                    }
                    else printf("%d ",1+((i+ang)%2));
                }
            }
        }
        puts("");
    }
}
