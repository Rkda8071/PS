#include<bits/stdc++.h>
using namespace std;
long long a,dap,ang;
int main(){
    scanf("%lld",&a);
    for(int i=3;i>=0;i--){
        ang = 0;
        for(int j=7;j>=0;j--)
            if(a&(1<<(i*8+j))) ang += (1<<j);
        dap += (ang<<((3-i)*8));
    }
    printf("%lld",dap);
    return 0;
}
