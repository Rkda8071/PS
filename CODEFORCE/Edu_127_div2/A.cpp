#include<bits/stdc++.h>
using namespace std;
char a[100];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int i,x=0,dap=0;
        scanf(" %s",a);
        for(i=1;a[i]!='\0';i++){
            if(a[x] != a[i]){
                if(i - x < 2) {dap=1; break;}
                x = i;
            }
        }
        if(dap || i - x < 2) printf("NO\n");
        else printf("YES\n");
    }
}