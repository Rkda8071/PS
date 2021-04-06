#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int n,k;
    scanf("%d",&t);
    while(t--){
        int ang = 0;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=k;i++) printf("a");
        for(int i=k+1;i<=n;i++) printf("%c",'a'+((++ang)%3));
        puts("");
    }
    return 0;
}
