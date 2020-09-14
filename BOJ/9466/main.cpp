#include<bits/stdc++.h>
using namespace std;
int n,s,e;
int t,cnt;
int a[100010],chk[100010],ang,dap;
void f(int x){
    if(chk[a[x]] == cnt){
        e = a[x];
        if(x!=e) ang = 1;
        else ang = 2;
        return;
    }
    if(chk[a[x]] > chk[0]){
        ang = 2; dap++;
        return;
    }else{
        chk[a[x]] = cnt;
        f(a[x]);
    }
    if(ang == 1){
        if(x == e) ang = 2;
        return;
    }
    if(ang == 2) {dap++; return;}
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        chk[0] = cnt;
        dap = 0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(chk[i] <= chk[0]){
                chk[i] = ++cnt; ang = 1;
                f(i);
            }
        }
        printf("%d\n",dap);
    }
    return 0;
}
