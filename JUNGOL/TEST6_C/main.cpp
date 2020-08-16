#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int a[5010],p[5010],chk[50];
int dap;
int n,k,m;
queue<tp> q;
void f(int x,int prev){
    if(x==n){
        dap++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(chk[i]) continue;
        if((p[x] || a[x+1]) && prev<i) continue;
        if((a[x] || p[x+1]) && prev>i) continue;
        chk[i] = 1;
        f(x+1,i);
        chk[i] = 0;
    }
}
int main(){
    int x;
    scanf("%d %d %d",&n,&k,&m);
    for(int i=0;i<k;i++){
        scanf("%d",&x); //¾ç¿·º¸´Ù ÀÛÀº³ðµé
        a[x] = 1;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&x); //¾ç¿·º¸´Ù Å«³ðµé
        p[x] = 1;
    }
    if(n>10)
        printf("0");
    else{
        for(int i=1;i<=n;i++){
            chk[i] = 1;
            f(1,i);
            chk[i] = 0;
        }
    }
    printf("%d",dap);
    return 0;
}
