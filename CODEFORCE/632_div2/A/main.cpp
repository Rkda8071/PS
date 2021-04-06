#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int main(){
    int t,n,m,sw;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        if(n%2==0 || m%2==0){
            sw = 1;
            for(int i=1;i<=n;i++){
                if(i!=1 && m%2==0) sw = (sw+1)%2;
                for(int j=1;j<=m;j++){
                    a[i][j] = (sw)?'W':'B';
                    sw = (sw+1)%2;
                }
            }
            a[1][1] = 'B';
        }else{
            sw = 0;
            for(int i=1;i<=n;i++){
                if(i!=1 && m%2==0) sw = (sw+1)%2;
                for(int j=1;j<=m;j++){
                    a[i][j] = (sw)?'W':'B';
                    sw = (sw+1)%2;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) printf("%c",a[i][j]);
            puts("");
        }
    }
    return 0;
}
