#include<bits/stdc++.h>
using namespace std;
int r,c,maxim;
char a[21][21];
int chk[30],xxx[4]={0,0,1,-1},yyy[4]={1,-1,0,0};
void f(int y,int x,int cnt){
    maxim = max(maxim,cnt);
    for(int i=0;i<4;i++){
        int xx = xxx[i]+x , yy = yyy[i]+y;
        if(yy>0 && yy<=r && xx>0 && xx<=c && !chk[a[yy][xx]-'A']){
            chk[a[yy][xx]-'A'] = 1;
            f(yy,xx,cnt+1);
            chk[a[yy][xx]-'A'] = 0;
        }
    }
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++) scanf("%s",a[i]+1);
    chk[a[1][1]-'A'] = 1;
    f(1,1,1);
    printf("%d",maxim);
    return 0;
}
