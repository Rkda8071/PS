#include<bits/stdc++.h>
using namespace std;
int ans,n,chk[30],d[30];
char a[101];
int g(int m){
    int ang = 0;
    for(int i=1;i<=m;i++) ang |= d[chk[i]];
    if(ang == (1<<26) - 1) return 1;
    return 0;
}
void f(int x){
    ans += g(x-1);
    for(int i=chk[x-1]+1;i<=n;i++){
        chk[x] = i;
        f(x+1);
        chk[x] = 0;
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",a);
        for(int j=0;a[j]!=0;j++) d[i] |= (1<<(a[j]-'a'));
    }
    f(1);
    printf("%d",ans);
}