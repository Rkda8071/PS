#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==1) printf("-1");
        else{
            for(int i=1;i<n;i++) printf("5");
            if((n-1)%6!=0)printf("7");
            else printf("4");
        }
        puts("");
    }
    return 0;
}
