#include<bits/stdc++.h>
using namespace std;

int n,maxim,x,cur;
int chk[100010];
int main(){
    scanf("%d",&n);
    n*=2;
    while(n--){
        scanf("%d",&x);
        if(!chk[x]){
            chk[x] = 1;
            maxim = max(maxim,++cur);
        }else --cur;
    }
    printf("%d",maxim);
    return 0;
}
