#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,dap=0;
        scanf("%d",&n);
        for(int i=1;i<31;i++){
            m = (1<<i)-1;
            //if(m>n) break;
            if(n%m==0) dap = n/m;
        }
        printf("%d\n",dap);
    }
    return 0;
}
