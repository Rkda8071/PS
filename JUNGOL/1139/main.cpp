#include <bits/stdc++.h>
using namespace std;
int n;
int a[21][21],mini = 2000000000,chk[21],cur[21],dap[21];
void f(int id,int hap){
    if(id == n){
        if(mini>hap){
            mini = hap;
            for(int i=0;i<n;i++) dap[i] = cur[i];
        }
    }
    for(int i=0;i<n;i++){
        if(!chk[i]){
            cur[id] = i; chk[i] = 1;
            f(id+1,hap+a[id][i]);
            cur[id] = 0; chk[i] = 0;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    f(0,0);
    printf("%d\n",mini);
    for(int i=0;i<n;i++) printf("%d ",dap[i]+1);
    return 0;
}
