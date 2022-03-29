#include<bits/stdc++.h>
using namespace std;
int a[30],k,n;
int f(int x,int hap){
    if(x==n){
        if(k==hap) return 1;
        else return 0;
    }
    return f(x+1,hap+a[x+1]) + f(x+1,hap);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%d",f(0,0) + ((k==0) ? -1 : 0));
}
