#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
    int t,sw;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&a,&b);
        sw = 0;
        for(int i=1;i<=n;i++){
            printf("%c",'a'+sw);
            if(b==++sw) sw=0;
        }
        puts("");
    }
    return 0;
}
