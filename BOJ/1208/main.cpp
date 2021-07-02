#include<bits/stdc++.h>
using namespace std;
long long dap;
int n,s,k;
int a[100],m[1500000];
int main(){
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int nn = n/2;
    for(int i=0;i<(1<<nn);i++){//1~nn, 0
        int hap = 0;
        for(int j=0;j<nn;j++)
            if((i&(1<<j)))
                hap+=a[j+1];
        m[++k] = hap;
    }
    sort(m+1,m+k+1);
    //for(int i=1;i<=k;i++) printf("%d %d\n",i,m[i]);
    for(int i=0;i<(1<<(n-nn));i++){
        int hap = 0;
        for(int j=0;j<n-nn;j++) // nn+1 ~ n
            if((i&(1<<j)))
                hap+=a[nn+j+1];
        int x = lower_bound(m+1,m+k+1,s-hap) - m;
        int y = upper_bound(m+1,m+k+1,s-hap) - m;
        //printf("[%d %d %d]\n",hap,x,y);
        if(x<=k && m[x] == s-hap)
            dap += (long long)(y-x);
    }
    if(s==0) dap--; // ÅÖ ºó ¼ø¿­ Á¦°Å
    printf("%lld",dap);
    return 0;
}
