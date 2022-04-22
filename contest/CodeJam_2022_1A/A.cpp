#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    for(int tt = 1; tt<=t; tt++){
        int n,chk[110]={0},last;
        char a[110]={0};
        scanf(" %s",a+1);
        for(n=1;a[n+1]!='\0';n++);
        last = n;
        for(int i=n-1;i>=1;i--){
            if(a[i] < a[last]) chk[i] = 1;
            if(a[i] != a[i-1]) last = i;
        }
        printf("Case #%d: ", tt);
        for(int i=1;i<=n;i++){
            printf("%c",a[i]);
            if(chk[i]) printf("%c",a[i]);
        }
        puts("");
    }
    return 0;
}