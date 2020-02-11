#include<bits/stdc++.h>
using namespace std;
int n,m,a[10],chk[10];
void f(int x){
    if(x == m){
        for(int i=0;i<m;i++) printf("%d ",a[i]);
        puts("");
        return;
    } else{
        for(int i=1;i<=n;i++){
            if(!chk[i]){
                chk[i] = 1; a[x] = i;
                f(x+1);
                chk[i] = a[x] = 0;
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    f(0);
    return 0;
}
