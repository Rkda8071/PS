#include<bits/stdc++.h>
using namespace std;
int f[41],n,m;
int l,r;
int main(){
    scanf("%d %d",&n,&m);
    f[1] = f[0] = 1;
    for(int i=2;i<=n;i++) f[i] = f[i-1] + f[i-2];

    // 1 ~ m-1 중에서 자유석
    for(int i=1;i<m;i++){ // i를 자유석으로 보냄
        for(int j=i-1;j>=1;j--) l += f[j-1]*f[m-i-1]; // i기준 왼쪽놈을 보낼 때
        for(int j=i+1;j<m;j++) l += f[m-j-1]*f[i-1]; // 오늘쪽놈
        l+=f[i-1]*f[m-i-1]; // 공석을 채우지 않을 때
    }

    for(int i=m+1;i<=n;i++){
        for(int j=i-1;j>m;j--) r += f[j-m-1]*f[n-i];
        for(int j=i+1;j<=n;j++) r += f[n-j]*f[i-m-1];
        r+=f[i-m-1]*f[n-i];
    }
    printf("%d",f[m-1]*f[n-m] + l*f[n-m] + r*f[m-1]);
    return 0;
}
