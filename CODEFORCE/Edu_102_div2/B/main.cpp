#include<bits/stdc++.h>
using namespace std;
int t,n,m,ang;
char a[500],b[500];
bool f(){
    for(int i=1;i<=ang;i++)
        if(a[i]!=b[i]) return false;
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",a+1,b+1);
        for(n=1;a[n+1]!=NULL;n++);
        for(m=1;b[m+1]!=NULL;m++);
        ang = (n*m)/__gcd(n,m);

        for(int i=1;i<=n;i++)
            for(int j=1;j<ang/n;j++)
                a[i+n*j] = a[i];
        for(int i=1;i<=m;i++)
            for(int j=1;j<ang/m;j++)
                b[i+m*j] = b[i];
        if(f()) for(int i=1;i<=ang;i++) printf("%c",a[i]);
        else printf("-1");
        puts("");
    }
    return 0;
}
