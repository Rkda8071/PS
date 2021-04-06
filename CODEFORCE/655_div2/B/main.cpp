#include<bits/stdc++.h>
using namespace std;
int f(int n){
    if(n%2 == 0) return 2;
    for(int i=3;i*i<=n;i+=2)
        if(n%i == 0) return i;
    return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ang = f(n);
        if(ang==1) printf("1 %d\n",n-1);
        else printf("%d %d\n",n/ang,n-(n/ang));
    }
    return 0;
}
