#include<bits/stdc++.h>
using namespace std;
int a[10][3],n=6;
bool f(int x,int k){
    if(x==n) return 1;
    bool chk = false;
    for(int i=k;i<=n;i++){
        for(int j=0;j<3;j++){
            if(a[x][j]>0 && a[i][2-j]>0){
                a[x][j]--; a[i][2-j]--;
                chk |= f(x,k+1);
                a[x][j]++; a[i][2-j]++;
            }
        }
    }
    if(a[x][0]+a[x][1]+a[x][2]==0) chk|=f(x+1,x+2);
    return chk;
}
int main(){
    for(int t=1;t<=4;t++){
        bool chk = true;
        for(int i=1;i<=6;i++) {
            scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
            if(a[i][0]+a[i][1]+a[i][2]!=5) chk = false;
        }
        if(chk) printf("%d ",f(1,2)?1:0);
        else printf("0 ");
    }
    return 0;
}
