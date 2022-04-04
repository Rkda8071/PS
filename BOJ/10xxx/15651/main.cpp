#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10];
void f(int x){
    if(x>m){
        for(int i=1;i<=m;i++) printf("%d ",a[i]);
        puts("");
        return;
    }
    for(int i=1;i<=n;i++){
        a[x] = i;
        f(x+1);
        a[x] = 0;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    f(1);
    return 0;
}
