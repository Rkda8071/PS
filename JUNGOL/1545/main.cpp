#include<bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
int d[1<<20][20];
void f(int x,int cur){
    if(x==((1<<n)-1))
    for(int i=0;i<n;i++){
        if(i==cur) continue;
        int ang = (x|(1<<i));
        if(d[ang][i] == 0 || d[ang][i]>d[cur][x] + a[cur][x]){
            d[ang][i] = d[cur][x] + a[cur][i];
            f(ang,i);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    d[0][0] = 1;
    f(0,0);
}
