#include<bits/stdc++.h>
using namespace std;
char a[200];
int main(){
    int n,chk,cnt,hap;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",a+1);
        chk = cnt = hap = 0;
        for(int i=1;a[i]!=NULL;i++){
            if(chk){
                if(a[i] == '0'){
                    ++cnt;
                } else{
                    hap += cnt;
                    cnt = 0;
                }
            } else if(a[i] == '1'){
                chk = 1; cnt = 0;
            }
        }
        printf("%d\n",hap);
    }
    return 0;
}
