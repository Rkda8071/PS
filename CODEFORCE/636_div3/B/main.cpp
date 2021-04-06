#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        n/=2;
        if(n%2) printf("NO\n");
        else{
            printf("YES\n");
            for(int i=1;i<=n;i++) printf("%d ",i*2);
            for(int i=1;i<n;i++) printf("%d ",i*2-1);
            printf("%d\n",n*3-1);
        }
    }
    return 0;
}
