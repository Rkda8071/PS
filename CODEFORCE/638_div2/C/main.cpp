#include<bits/stdc++.h>
using namespace std;
int t,n,k,chk;
char d[100100];
int a[100100];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        scanf("%s",d+1);
        for(int i=1;i<=n;i++){
            a[i] = d[i]-'a'+1;
        }
        sort(a+1,a+n+1);
        if(a[1]==a[k]){
            printf("%c",a[1]+'a'-1);
            chk = a[k+1];
            for(int i=k+1;i<=n;i++){
                if(a[i]!=chk){
                    chk = -1;
                    break;
                }
            }
            if(chk == -1)
                for(int i=k+1;i<=n;i++) printf("%c",a[i]+'a'-1); // 균형이 안맞을때
            else
                for(int i=k+1;i<=n;i+=k) printf("%c",a[i]+'a'-1);
        }else
            printf("%c",a[k]+'a'-1);

        puts("");
    }
    return 0;
}
