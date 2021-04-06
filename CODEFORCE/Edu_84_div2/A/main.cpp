#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        if(k<=sqrt(n) && (n-(k*k))%2==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
