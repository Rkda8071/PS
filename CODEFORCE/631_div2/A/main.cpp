#include<bits/stdc++.h>
using namespace std;
int n,x,k;
int a[110];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&x);
        for(int i=1;i<=100;i++) a[i] = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            a[k] = 1;
        }
        int v = 0;
        for(int i=x;i<=100;i++){
            int y = x, j = i;
            while(y>=0 && j>0){
                if(!a[j]) --y;
                --j;
            }
            if(j>1) break;
            v = max(i-j+y,v);
        }
        printf("%d\n",v);
    }
    return 0;
}
