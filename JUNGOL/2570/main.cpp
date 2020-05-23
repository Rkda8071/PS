#include<bits/stdc++.h>
using namespace std;
char a[20];
int dap[20];
int n;
void maxim(){
    int cur = 10,chk = 0;
    a[n+1] = '<';
    for(int i=1;i<=n+1;i++){
        if(a[i] == '>'){
            for(int j=i;j>chk;j--) dap[j] = --cur;
            chk = i;
        }
    }
    for(int i=n+1;i>chk;i--) dap[i] = --cur;
    for(int i=1;i<=n+1;i++) printf("%d",dap[i]);
}
void mini(){
    int cur = 0,chk = 0;
    a[n+1] = '>';
    for(int i=1;i<=n+1;i++){
        if(a[i] == '<'){
            for(int j=i;j>chk;j--) dap[j] = cur++;
            chk = i;
        }
    }
    for(int i=n+1;i>chk;i--) dap[i] = cur++;
    for(int i=1;i<=n+1;i++) printf("%d",dap[i]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf(" %c",&a[i]);
    maxim();
    puts("");
    mini();

    return 0;
}
