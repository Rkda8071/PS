#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        int dap[10] = {0};
        scanf("%d",&x);
        for(int i=9;i>=1;i--){
            if(x<i){
                dap[i] = x;
                x-=x;
                break;
            }else{
                dap[i] = i;
                x-=i;
            }
        }
        if(x!=0) printf("-1");
        else{
            for(int n=1;n<=9;n++){
                if(dap[n]){
                    for(int i=n;i<=9;i++) printf("%d",dap[i]);
                    break;
                }
            }
        }
        puts("");
    }
    return 0;
}
