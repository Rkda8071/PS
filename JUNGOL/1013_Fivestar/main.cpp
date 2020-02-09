#include<bits/stdc++.h>
using namespace std;
char a[10][20];
int n,m,mini = 2000000000,chk1[10][20],chk[10][20];
bool vchk(int y,int x){
    if(x+4>m) return false;
    for(int i=0;i<5;i++) if(a[y][x+i]=='.') return false;
    return true;
}
bool hchk(int y,int x){
    if(y+4>n) return false;
    for(int i=0;i<5;i++) if(a[y+i][x]=='.') return false;
    return true;
}
void f(int y,int x,int cnt){
    if(x>m) {
        if(y<n) f(y+1,1,cnt);
        else{
            mini = min(mini,cnt);
            return;
        }
    }
    if(mini<=cnt) return;
    if(a[y][x] == '.' || chk[y][x] || chk1[y][x]){
        f(y,x+1,cnt);
    }
    if(a[y][x] == '*'){
        if(vchk(y,x)){
            for(int i=0;i<5;i++) chk[y][x+i] = 1;
            f(y,x+1,cnt+1);
            for(int i=0;i<5;i++) chk[y][x+i] = 0;
        }
    }
}
void h(int y,int x,int cnt){
    if(x>m) {f(1,1,cnt); return;}
    h(y,x+1,cnt);
    if(hchk(y,x)){
        for(int i=1;i<=5;i++) chk1[i][x] = 1;
        h(y,x+1,cnt+1);
        for(int i=1;i<=5;i++) chk1[i][x] = 0;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);

    h(1,1,0);
    printf("%d",mini==2000000000 ? -1 : mini);
}
