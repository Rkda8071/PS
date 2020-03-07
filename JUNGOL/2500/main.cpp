#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[210],d[210][210];
void init(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i-1] == a[i]) {--i; --n;}
    }
}
int main(){
    init();
    for(int k=1;k<n;k++){
        for(int s=1;s<=n-k;s++){
            int e = s+k;
            if(a[s] == a[e]) {
                d[s][e] = d[s+1][e-1] + 1; // s~e±îÁö »ö±òÀÌ a[s]·Î ¹Ù²ñ
            }
            else d[s][e] = 1000000000;
            for(int m=s+1;m<e;m++)
                d[s][e] = min(d[s][e],d[s][m]+d[m][e]);
            for(int m=s;m<e;m++)
                d[s][e] = min(d[s][e],d[s][m]+d[m+1][e]+1);
        }
    }
    printf("%d",d[1][n]);
    return 0;
}
