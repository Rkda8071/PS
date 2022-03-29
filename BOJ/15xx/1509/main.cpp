#include<bits/stdc++.h>
using namespace std;
char in[5010],a[5010];
int p[5010],d[5010];
int n;
void f(){
    int r=0,c=0; //end,center
    for(int i=1;i<=2*n-1;i++){
        if(i<=r) p[i] = min(r-i,p[c+c-i]); // c-(i-c)
        else p[i] = 0;
        while(i+p[i]+1 <= 2*n-1){
            if(a[i+p[i]+1] == a[i-p[i]-1]) p[i]++;
            else break;
        }
        if(r<i+p[i]){
            r = i+p[i];
            c = i;
        }
    }
}
int main(){
    scanf("%s",in+1);
    for(n=1;in[n+1]!=NULL;n++);
    for(int i=1;i<=n;i++){
        a[i*2-1] = in[i];
        a[i*2] = '#';
    }
    f();
    for(int i=1;i<=n*2-1;i++) d[i] = 2000000000;
    for(int i=1;i<=n*2-1;i++){
        if(p[i]>0 && a[i+p[i]] == '#') p[i]--;
        for(int j=1-(i%2);j<=p[i];j+=2)
            d[(i+j+1)/2] = min(d[(i+j+1)/2],d[(i-j+1)/2 - 1]+1);
    }
    printf("%d",d[n]);
    return 0;
}
