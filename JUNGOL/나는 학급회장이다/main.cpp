#include<bits/stdc++.h>
using namespace std;
int a[4][4];
int cmp(int x,int y){
    for(int i=0;i<=3;i++){
        if(a[x][i]>a[y][i]) return x;
        else if(a[x][i]<a[y][i]) return y;
    }
    return 0;
}
int main(){
    int n;
    int x,y,z;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=1;j<=3;j++){
            scanf("%d",&x);
            a[j][0] += x; a[j][x]++;
        }
    }
    for(int i=0;i<=3;i++) a[0][i] = a[2][i];
    printf("%d ",cmp(1,cmp(2,3)));
    printf("%d",max(a[1][0],max(a[2][0],a[3][0])));
    return 0;
}
