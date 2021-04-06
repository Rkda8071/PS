#include<bits/stdc++.h>
using namespace std;
int t,n,dap;
char a[100100];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",a+1);
        dap = 0;
        for(n=1;a[n+1]!=NULL;n++);
        for(int i=1;i<n;i++){
            if(a[i] == a[i+1] && a[i] == a[i+2] && a[i] != '@'){
                a[i+1] = a[i+2] = '@';
                dap+=2;
            }else if(a[i] == a[i+1] && a[i] != '@'){
                a[i+1] = '@';
                dap++;
            }else if(a[i] == a[i+2] && a[i] != '@'){
                a[i] = a[i+2] = '@';
                dap++;
            }
        }
        printf("%d\n",dap);
    }
    return 0;
}
