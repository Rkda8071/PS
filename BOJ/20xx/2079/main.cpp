#include<bits/stdc++.h>
using namespace std;
int n,k,d[4010],p[4010];
char a[4010],b[2010];
int main(){
    scanf("%s",b+1);
    for(n=1;b[n+1]!=NULL;n++);
    for(int i=1;i<=n;i++){
        a[i*2-1] = b[i];
        a[i*2] = '*';
    }
    n = n*2;
    a[0] = a[n] = '*';
    for(int i=1;i<n;i++){
        k = min(i,n-i);
        for(int j=1;j<=k;j++){
            if(a[i+j] == a[i-j]) p[i] = j;
            else break;
        }
    }
    for(int i=1;i<=n;i++) d[i] = 2000000000;
    for(int i=1;i<=n;i++){
        if(a[i] == '*'){
            for(int j=2;j<=p[i];j+=2){
                d[i+j] = min(d[i+j],d[i-j]+1);
            }
        } else{
            for(int j=1;j<=p[i];j+=2){
                d[i+j] = min(d[i+j],d[i-j]+1);
            }
        }
    }
    printf("%d",d[n]);
    return 0;
}
