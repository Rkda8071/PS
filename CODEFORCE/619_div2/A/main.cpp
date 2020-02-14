#include<bits/stdc++.h>
using namespace std;
char a[200],b[200],c[200];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int chk = 0;
        scanf("%s %s %s",a+1,b+1,c+1);
        for(int i=1;a[i]!=NULL;i++){
            if(a[i] != c[i] && b[i] != c[i]) {
                chk = 1;
                break;
            }
        }
        if(chk) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
