#include<bits/stdc++.h>
using namespace std;
int n,a[100010],cnt[4],mini = 2000000000;
void f(int x1,int x2,int x3){
    int s,dap = 0, d[4][4]={0};
    for(int i=1;i<=cnt[x1];i++)
        if(a[i]!=x1) d[x1][a[i]]++; //x1자리에 이상한거
    s = cnt[x1];
    for(int i=s+1;i<=s+cnt[x2];i++)
        if(a[i]!=x2) d[x2][a[i]]++; //x2자리에 이상한거
    s = cnt[x1]+cnt[x2];
    for(int i=s+1;i<=n;i++)
        if(a[i]!=x3) d[x3][a[i]]++;
    // 계산
    for(int i=1;i<3;i++){
        for(int j=i+1;j<=3;j++){
            s = min(d[i][j],d[j][i]);
            d[i][j]-=s; d[j][i]-=s; dap+=s;
        }
    } s = 0;
    for(int i=1;i<3;i++)
        for(int j=i+1;j<=3;j++)
            s = max(d[i][j],d[j][i]);

    dap += s*2;
    mini = min(dap,mini);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(i==j) continue;
            for(int l=1;l<=3;l++){
                if(i==l || j==l) continue;
                f(i,j,l);
            }
        }
    }
    printf("%d",mini);
    return 0;
}
