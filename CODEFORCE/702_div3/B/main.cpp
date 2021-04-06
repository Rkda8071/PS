#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[30100];
int main(){
    scanf("%d",&t);
    while(t--){
        int c[3] = {0},dap = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) c[a[i]%3]++;
        // 0 -> 1 -> 2 -> 0
        for(int i=0;i<3;i++){
            if(c[i]>n/3){
                dap += c[i]-n/3;
                c[(i+1)%3] += c[i]-n/3;
                c[i] = n/3;
            }
        }
        for(int i=0;i<3;i++){
            if(c[i]>n/3){
                dap += c[i]-n/3;
                c[(i+1)%3] += c[i]-n/3;
                c[i] = n/3;
            }
        }
        printf("%d\n",dap);
    }
    return 0;
}
