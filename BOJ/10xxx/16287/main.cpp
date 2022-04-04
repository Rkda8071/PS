#include<bits/stdc++.h>
#define nex a[i]+a[j]
using namespace std;

int w,n;
int a[5100];
int l[400100],r[400100];
bool solve(){
    for(int i=1;i<=w;i++) if(i<=400000 && w-i<=400000 && l[i]<r[w-i]) return true;
    return false;
}
int main(){
    scanf("%d %d",&w,&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=400000;i++) l[i] = 2000000000;
    for(int i=1;i<=n-3;i++)
        for(int j=i+1;j<=n-2;j++)
            l[nex] = min(l[nex],j);

    for(int i=3;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            r[nex] = max(r[nex],i);
    if(solve()) printf("YES");
    else printf("NO");
    return 0;
}
