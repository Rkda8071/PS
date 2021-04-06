#include<bits/stdc++.h>
using namespace std;
char a[200010];
int n,k;
int f(int i){
    int maxim = 0,cnt[30]={0};
    for(int j=i;j<=n;j+=k)
        maxim = max(maxim,++cnt[a[j]-'a']);
    return (n/k) - maxim;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int dap = 0;
        scanf("%d %d",&n,&k);
        scanf("%s",a+1);
        for(int i=1;i<=k;i++)
            dap += f(i);
        printf("%d\n",dap);
    }
    return 0;
}
