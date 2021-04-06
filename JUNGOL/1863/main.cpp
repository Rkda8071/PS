#include<bits/stdc++.h>
using namespace std;
int chk[50010],d[50010];
int n,m;
int fin(int x){
    if(d[x]==x) return x;
    return d[x] = fin(d[x]);
}
void uni(int x,int y){
    x = fin(x); y = fin(y);
    if(x!=y) d[y] = x;
}
void f(){
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) d[i] = i;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        uni(x,y);
    }
}
int main(){
    f();
    int cnt = 0;
    for(int i=1;i<=n;i++){
        int x = fin(i);
        if(!chk[x]){++cnt; chk[x]=1;}
    }
    printf("%d",cnt);
    return 0;
}
