#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,x,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        x = n/9;
        x = (10*x) + (n%9);
        printf("%d",x);
        if(t) puts("");
    }
    return 0;
}
