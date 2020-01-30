#include<bits/stdc++.h>
using namespace std;
int a[21],n,m,mini = 2000000000;
void f(int lev,int x1,int x2,int cnt){
    if(lev == m){
        if(mini>cnt) mini = cnt;
        return;
    }
    if(x1 == a[lev] || x2 == a[lev]) f(lev+1,x1,x2,cnt);
    else{
        f(lev+1,a[lev],x2,cnt+abs(x1-a[lev]));
        f(lev+1,x1,a[lev],cnt+abs(x2-a[lev]));
    }
}
int main(){
    scanf("%d",&n);
    int x1,x2;
    scanf("%d %d",&x1,&x2);
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    f(0,x1,x2,0);
    printf("%d",mini);
}
