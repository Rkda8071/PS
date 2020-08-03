#include<bits/stdc++.h>
using namespace std;
int d[1000001],path[1000001];
int main(){
    int n;
    scanf("%d",&n);
    d[1] = 1;
    for(int i=1;i<n;i++){
        if(i*3<=n) if(!d[i*3] || d[i*3]>d[i]+1) {d[i*3] = d[i]+1; path[i*3] = 3;}
        if(i*2<=n) if(!d[i*2] || d[i*2]>d[i]+1) {d[i*2] = d[i]+1; path[i*2] = 2;}
        if(!d[i+1] || d[i+1]>d[i]+1) {d[i+1] = d[i]+1; path[i+1] = 1;}
    }
    printf("%d\n",d[n]-1);

    while(n){
        printf("%d ",n);
        if(!path[n]) break;
        if(path[n]==1) --n;
        else if(path[n]==2) n/=2;
        else n/=3;
    }
    return 0;
}
