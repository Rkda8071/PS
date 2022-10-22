#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int sum = 0, a[4] = {1000000,1000000,1000000,1000000};
        for(int k=0;k<3;k++){
            for(int x,j=0;j<4;j++){
                scanf("%d",&x);
                a[j] = min(a[j],x);
            }
        }
        for(int j=0;j<4;j++) sum += a[j];
        printf("Case #%d: ",i);
        if(sum >= 1000000){
            for(int j=0;j<4;j++){
                sum -= a[j];
                a[j] = 0;
                if(sum < 1000000){
                    a[j] = 1000000 - sum;
                    sum = 1000000;
                }
                printf("%d ",a[j]);
            }
            puts("");
        }else{
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
