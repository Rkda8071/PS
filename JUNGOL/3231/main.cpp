#include<bits/stdc++.h>
using namespace std;
int n,m,h;
int a[1010][1010],b[1010][1010];
int main(){
    scanf("%d %d %d",&n,&m,&h);
    for(int i=0;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++) scanf("%d",&b[i][j]);
    }
}
