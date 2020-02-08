#include<bits/stdc++.h>
#define n 4
using namespace std;
int a[5][5],maxim = 500;
bool chk(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j] != i*n+j-n) return 0;
    return 1;
}
void f(int r,int c,int cnt){
    if(chk() == 1){
        maxim = min(maxim,cnt);
        return;
    }
    if(cnt + 1 > maxim) return;
    for(int i=r;i<=n;i++){  // 1 ÁÂ¿ì
        for(int j=1;j<=3;j++){
            for(int l=3;l>=1;l--) swap(a[l+1][i],a[l][i]);
            f(r+1,c,cnt+1);
        }
        for(int l=3;l>=1;l--) swap(a[l+1][i],a[l][i]);
    }

    for(int i=c;i<=n;i++){  // 2 »óÇÏ
        for(int j=1;j<=3;j++){
            for(int l=3;l>=1;l--) swap(a[i][l+1],a[i][l]);
            f(1,c+1,cnt+1);
        }
        for(int l=3;l>=1;l--) swap(a[i][l+1],a[i][l]);
    }
}
int main(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    f(1,1,0);
    printf("%d",maxim);
}
