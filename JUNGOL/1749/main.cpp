#include<bits/stdc++.h>
using namespace std;
int a[3],d[510][510];

int main(){
    for(int i=0;i<3;i++) scanf("%d",&a[i]);
    for(int i=0;i<=500;i++){
        for(int j=0;j<=500;j++){
            for(int k=0;k<3;k++){
                if(d[i][j]==0){
                    if(i+a[k]<=500) d[i+a[k]][j] = 1;
                    if(j+a[k]<=500) d[i][j+a[k]] = 1;
                }
            }
        }
    }
    for(int i=1;i<=5;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%c\n",(d[x][y]?'A':'B'));
    }
    return 0;
}
