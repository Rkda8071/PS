#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
    int t;
    int n,mini;
    scanf("%d",&t);
    while(t--){
        mini = 2000000000;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n*2+1);
        for(int i=1;i<=n;i++){
            for(int j=n+1;j<=n+i;j++){
                if(mini>a[j] - a[i]){
                    mini = a[j]-a[i];
                } else break;
            }
        }
        printf("%d\n",mini);
    }
    return 0;
}
