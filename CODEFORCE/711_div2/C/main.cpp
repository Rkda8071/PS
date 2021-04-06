#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,k;
int a[1010][1010];
int f(int x,int y){
    if(y==k) return 1;
    if(x==n+1) return 1;
    if(a[x][y]) return a[x][y];
    return a[x][y] = (f(n-x+2,y+1) + f(x+1,y))%mod;
}

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&k); //x,y
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++) a[i][j] = 0;
        printf("%d\n",f(1,1));
    }
    return 0;
}
