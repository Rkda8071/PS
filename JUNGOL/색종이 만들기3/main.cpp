#include<bits/stdc++.h>
using namespace std;
int d[1100][1100],xxx[4] = {0,1,0,1},yyy[4] = {0,0,1,1},lev = 1;
char a[30000];
void g(int v,int y,int x,int yy,int xx){
    for(int i=y;i<=yy;i++) for(int j=x;j<=xx;j++) d[i][j] = v;
    return;
}
void f(int y,int x,int n){
    for(int i=0;i<4;i++){
        int yy = y + yyy[i]*n , xx = x + xxx[i]*n;
        if(a[lev] == 'X'){
            ++lev;
            f(yy,xx,n/2);
        }
        else {
            g(a[lev++]-'0',yy,xx,yy+n-1,xx+n-1);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    if(a[0] == 'X') f(1,1,n/2);
    else g(a[0]-'0',1,1,n,n);
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d ",d[i][j]);
        puts("");
    }
    return 0;
}
