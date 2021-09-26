#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010], b[100010];
void init(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
}
int main(){
    init();
    int ai,bi,mini = 2000000000;
    ai = bi = 1;
    for(int i=1;i<=n;i++){
        int x = lower_bound(b+1,b+m+1,a[i]) - b;
        if(x>=n) x--;
        x++;
        if(m>1) mini = min(mini,abs(a[i]-b[x]));
        mini = min(mini,abs(a[i]-b[x-1]));
    }
    printf("%d",mini);
}


