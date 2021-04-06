#include<bits/stdc++.h>
using namespace std;
int n,w;
int a[100100],b[100],c[100];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int dap = 0;
        scanf("%d %d",&n,&w);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);

        int k=1,m=0; b[0]=0; c[0]=1;
        for(int i=1;i<=n;i++){
            while(k<a[i]){k*=2; b[++m]=0; c[m]=k;}
            b[m]++;
        }

        while(n){
            ++dap;
            int hap=0;
            for(int i=m;i>=0;i--){
                int k = min(b[i],(w-hap)/c[i]);
                hap += c[i]*k; b[i]-=k; n-=k;
            }
            w = hap;
        }
        printf("%d\n",dap);
    }
    return 0;
}
