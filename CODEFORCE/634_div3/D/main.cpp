#include<bits/stdc++.h>
using namespace std;
int t,n=9;
char a[50][50];
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i*3+j+1][i+j*3+1]!='1') a[i*3+j+1][i+j*3+1] = '1';
                else a[i*3+j+1][i+j*3+1] = '2';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) printf("%c",a[i][j]);
            puts("");
        }
    }
    return 0;
}
