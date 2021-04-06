#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100];
int f(int x,int y){
    int cnt = 0;
    while(x*2<y){
        cnt++;
        x*=2;
    }
    return cnt;
}
int main(){
    scanf("%d",&t);
    while(t--){
        int dap = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0] = a[n+1] = 0;
        for(int i=1;i<=n;i++){
            dap += f(a[i],a[i-1]) + f(a[i],a[i+1]);
        }
        printf("%d\n",dap);
    }
    return 0;
}
