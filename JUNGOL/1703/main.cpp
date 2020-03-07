#include<bits/stdc++.h>
using namespace std;
int n;
char a[110];
int d[101][101],h[101][101],path[101][101];
void trace(int l,int r){
    if(l>=r) return;
    int m = path[l][r];
    if(m==-1) {
        printf("%d %d\n",l,r);
        trace(l+1,r-1);
    } else {
        trace(l,m);
        trace(m+1,r);
    }
}
int main(){
    scanf("%d %s",&n,a+1);
    for(int k=1;k<n;k+=2){
        for(int s=1;s<n;s++){
            int e = s+k;
            if(a[s]!=a[e] && d[s+1][e-1]!=1000000000){
                d[s][e] = d[s+1][e-1] + k + (h[s+1][e-1]+1)*2;
                h[s][e] = h[s+1][e-1]+1;
                path[s][e] = -1;
            } else d[s][e] = 1000000000;

            for(int m=s+1;m<e;m+=2){
                if(d[s][e]>d[s][m]+d[m+1][e]){
                    d[s][e] = d[s][m] + d[m+1][e];
                    h[s][e] = max(h[s][m],h[m+1][e]);
                    path[s][e] = m;
                }
            }
        }
    }
    printf("%d\n",d[1][n]);
    trace(1,n);
    return 0;
}
