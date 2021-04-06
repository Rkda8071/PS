#include<bits/stdc++.h>
using namespace std;
int n;
char in[50100];
char a[50100],b[50100];
bool chk;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %s",&n,in+1);
        chk = false;
        for(int i=1;i<=n;i++){
            if(in[i] == '2'){
                if(chk){a[i] = '0'; b[i] = '2';}
                else {a[i] = '1'; b[i] = '1';}
            } else if(in[i] == '1'){
                if(chk){a[i] = '0'; b[i] = '1';}
                else{a[i] = '1'; b[i] = '0'; chk = true;}
            } else { a[i] = b[i] = '0';}
        }
        for(int i=1;i<=n;i++) printf("%c",a[i]);
        puts("");
        for(int i=1;i<=n;i++) printf("%c",b[i]);
        puts("");
    }
    return 0;
}
