#include<bits/stdc++.h>
using namespace std;
int k,t,n,m;
int main(){
    scanf("%d %d",&k,&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int x,y;
        x=y=0;
        for(int i=1;i<=k;i++){
            x = min(i,n);
            if(k-i+x<y) break;
            y = min(i,m);
            if(k-i+y<x) break;
        }
        if(x==n && y==m) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
