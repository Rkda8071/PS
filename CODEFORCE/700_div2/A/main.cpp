#include<bits/stdc++.h>
using namespace std;
int t;
char a[100];
int main() {
    scanf("%d",&t);
    while (t--){
        scanf("%s",a+1);
        for(int i=1;a[i]!=NULL;i++){
            if(i%2){
                if(a[i] == 'a') a[i] = 'b';
                else a[i] = 'a';
            }else{
                if(a[i] == 'z') a[i] = 'y';
                else a[i] = 'z';
            }
            printf("%c",a[i]);
        }
        puts("");
    }
}
