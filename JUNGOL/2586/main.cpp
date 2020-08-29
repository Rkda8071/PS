#include<bits/stdc++.h>
using namespace std;
int m,n=8;
int a[10][10],r[10],c[10];
int chk[10][10];
int main(){
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[i][j] -= m;
            r[j] += a[i][j];
            c[i] += a[i][j];
        }
    }
    int m1,m2,cnt = 0;
    while(++cnt<=n*n){
        m1 = m2 = 1;
        for(int i=2;i<=n;i++) if(r[m1]<r[i]) m1 = i;
        for(int i=2;i<=n;i++) if(c[m2]<c[i]) m2 = i;
        if(r[m1]<=0 && c[m2]<=0) break;

        chk[m1][m2]=1;
        a[m1][m2]++; r[m1]++; c[m2]++;
        for(int i=1;i<=n;i++){
            a[m1][i]--; r[m1]--; c[i]--;
            a[i][m2]--; r[i]--; c[m2]--;
        }
    }
    cnt = 0;
    while(++cnt<=n*n){
        m1 = m2 = 1;
        for(int i=2;i<=n;i++) if(r[m1]>r[i]) m1 = i;
        for(int i=2;i<=n;i++) if(c[m2]>c[i]) m2 = i;
        if(r[m1]>=0 && c[m2]>=0) break;

        chk[m1][m2]=-1;
        a[m1][m2]--; r[m1]--; c[m2]--;
        for(int i=1;i<=n;i++){
            a[m1][i]++; r[m1]++; c[i]++;
            a[i][m2]++; r[i]++; c[m2]++;
        }
        r[m1]+=n; c[m2]+=n;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(chk[i][j] == 0) printf(". ");
            else if(chk[i][j] == 1) printf("+ ");
            else printf("- ");
        }
        puts("");
    }
    return 0;
}
