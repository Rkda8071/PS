#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int r,b;
int d[510][50100];
int hap(int x){return x*(x+1)/2;}
void init(){
    d[1][0] = d[1][1] = 1;
    for(int i=1;i<500;i++){
        for(int j=0;j<=min(hap(i),50000);j++){
            d[i+1][j] = (d[i+1][j] + d[i][j]) % mod;
            if(j+i+1<=50000){
                d[i+1][j+i+1] = (d[i+1][j+i+1] + d[i][j]) % mod;
            }
        }
    }
    for(int i=1;i<=500;i++){
        for(int j=0;j<min(hap(i),50000);j++){
            d[i][j+1] = (d[i][j+1] + d[i][j]) % mod;
        }
    }

}
int main(){
    int t;
    scanf("%d",&t);
    init();
    while(t--){
        int ans = 0;
        scanf("%d %d",&r,&b);
        for(int i=1;i<=500;i++){
            int left, right;
            left = hap(i) - min(b,hap(i));// b가능?
            right = min(r,hap(i));// r가능?
            if(right<left) continue;
            if(left == 0)
                ans = (ans + d[i][right]) % mod;
            else
                ans = (ans + d[i][right] - d[i][left-1]) % mod;
            ans = (ans + mod) % mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
