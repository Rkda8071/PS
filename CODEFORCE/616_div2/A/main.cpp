#include<bits/stdc++.h>
using namespace std;
char a[3100];
int main(){
    int n,t,hap;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",a+1);
        for(int i=1;i<=n;i++){
            if((a[i]-'0')%2==0){
                for(int j=i;j<n;j++) a[j] = a[j+1];
                --n; --i;
            }
        }
        if(n%2) n--;
        if(n<=1) printf("-1");
        else for(int i=1;i<=n;i++) printf("%c",a[i]);
        if(t>0)puts("");
    }
    return 0;
}
