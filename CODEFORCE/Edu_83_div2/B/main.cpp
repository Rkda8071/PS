#include<bits/stdc++.h>
using namespace std;
int t;
int a[110],n,chk[110],d[210];
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}

int main(){
    scanf("%d",&t);
    while(t--){
        init();
        sort(a+1,a+n+1,greater<int>());
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}
