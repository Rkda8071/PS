#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int n,chk;
        char a[110]={0};
        scanf("%s",a+1);
        for(n=1;a[n+1]!=NULL;n++);
        chk = a[1]-'0';
        for(int i=2;i<=n;i++){
            if(chk!=a[i]-'0') chk=100;
        }
        if(chk==100) for(int i=1;i<=n;i++) printf("10");
        else for(int i=1;i<=n;i++) printf("%c",a[i]);
        puts("");
    }
    return 0;
}
