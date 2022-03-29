#include<bits/stdc++.h>
using namespace std;
int a[30][30];
bool chk[30][30];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || i==k || j==k) continue;
                if(a[i][j] == a[i][k] + a[k][j]){
                    chk[i][j] = true;
                } else if(a[i][j] > a[i][k] + a[k][j]){
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    int hap = 0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(!chk[i][j]) hap += a[i][j];
        }
    }
    printf("%d",hap);
    return 0;
}

