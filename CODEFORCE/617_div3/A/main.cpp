#include<bits/stdc++.h>
using namespace std;
int hap;
int main(){
    int t,n,x;
    scanf("%d",&t);
    while(t--){
        hap = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            hap += x;
        }
        if(hap%2 == 1) printf("YES");
        else printf("NO");
        if(t) puts("");
    }
    return 0;
}
