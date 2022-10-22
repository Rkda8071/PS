#include<bits/stdc++.h>
using namespace std;

int main(){
    int dap = 1;
    int n,m;
    int x,d;
    int my,mx;
    scanf("%d %d %d %d %d %d",&n,&m,&x,&d,&my,&mx);
    if(d==0){ // 왼쪽
        if(my == 1 && mx>x) dap = 0;
        if(my == n && n%2) dap = 0;
    }else{
        if(my == 1 && mx<x) dap = 0;
        if(my == n && n%2==0) dap = 0;
    }
    if(dap == 0) printf("YES!");
    else printf("NO...");
}