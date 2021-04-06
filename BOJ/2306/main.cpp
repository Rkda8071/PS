#include<bits/stdc++.h>
using namespace std;
char a[510];
int d[510][510];
bool chk(int x,int y){ return (a[x] == 'g' && a[y] == 'c') || (a[x] == 'a' && a[y] == 't');}

int main(){
    int n;
    scanf("%s",a+1);
    for(n=1;a[n+1]!=NULL;n++);
    for(int k=1;k<n;k++){
        for(int i=1;i<=n-k;i++){
            if(chk(i,i+k)) d[i][i+k] = d[i+1][i+k-1] + 2;
            for(int j=i;j<=i+k;j++)
                d[i][i+k] = max(d[i][i+k],d[i][j] + d[j][i+k]);
        }
    }
    printf("%d",d[1][n]);
    return 0;
}
