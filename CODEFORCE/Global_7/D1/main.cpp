#include<bits/stdc++.h>
using namespace std;
char a[5010],b[5010];
int d[5010],c[5010];
void manachers(int n) {
    for (int i = 0; i < n; i++){
        b[i*2] = '#';
        b[i*2+1] = a[i];
    }
    b[n*2] = '#';
    int r = 0, p = 0;
    for (int i = 0; i < n; i++){
        if (i <= r)
            d[i] = min(d[2*p-i], r-i);
        else
            d[i] = 0;

        while (i-d[i]-1 >= 0 && i+d[i]+1 < n
               && b[i-d[i]-1] == b[i+d[i]+1])
            d[i]++;

        if (r < i+d[i]){
            r = i+d[i];
            p = i;
        }
    }
    for(int i=0;i<n/2;i++)
        c[(i-d[i]+1)/2] = max(d[i],c[(i-d[i]+1)/2]);
    for(int i=n-1;i>=n/2;i--)
        c[(i+d[i]-1)/2] = max(d[i],c[(i+d[i]-1)/2]);
}
void solve(){
    scanf("%s",a);
    int n = strlen(a);
    for(int i=0;i<=n*2+1;i++) {d[i] = 0; c[i] = 0;}
    manachers(n*2+1);
    for(int i=1;i<n;i++) c[i] = max(c[i],c[i-1]-2);
    for(int i=n-2;i>=0;i--) c[i] = max(c[i],c[i+1]-2);

    int mi=0,maxim=0;
    for(int i=0;i<n;i++){
        //maxim = c[i];
        if(maxim < c[i]+i*2){
            maxim = c[i]+i*2;
            mi = i;
        }
        if(maxim < c[n-i-1]+i*2){
            maxim = c[n-i-1]+i*2;
            mi = n-i-1;
        }
        if(a[i]!=a[n-i-1]) break;
    }
    if(mi<n/2){
        for(int i=0;i<mi;i++)
            printf("%c",a[i]);
        for(int i=mi;i<mi+c[mi];i++)
            printf("%c",a[i]);
        for(int i=n-mi;i<n;i++)
            printf("%c",a[i]);
    } else{
        for(int i=0;i<n-mi-1;i++)
            printf("%c",a[i]);
        for(int i=mi-c[mi]+1;i<mi;i++)
            printf("%c",a[i]);
        for(int i=mi;i<n;i++)
            printf("%c",a[i]);
    }
    puts("");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
