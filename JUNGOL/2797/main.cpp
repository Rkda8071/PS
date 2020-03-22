#include<bits/stdc++.h>
using namespace std;
int chk[2010][2010],cnt;
int f(int x,int y){
    if(y==0) return x;
    return f(y,x%y);
}
int main(){
    int s,e;
    scanf("%d %d",&s,&e);
    for(int i=s;i<=e;i++){
        for(int j=1;j<=i;j++){
            int m = f(i,j);
            if(!chk[i/m][j/m]){
                cnt++;
                chk[i/m][j/m] = 1;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
