#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[60][20];
struct A{
    ll x;
    bool chk;
    bool operator<(const A &r){
        return x<r.x;
    }
}d[20];
ll f(int x){
    if(x==0) return 1L;
    if(x==1) return 10L;
    return 10L * f(x-1);
}
int main(){
    int n;
    ll hap = 0L;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]);
    }
    for(int i=1;i<=n;i++){
        int m;
        for(m=0;a[i][m]!=NULL;m++);
        d[a[i][0]-'A'].chk = true;
        for(int j=0;j<m;j++){
            d[a[i][j]-'A'].x += f(m-j-1);
        }
    }
    sort(d,d+10);
    if(d[0].chk){
        for(int i=1;i<=9;i++){
            if(!d[i].chk) {
                A ang = d[i];
                for(int j=i;j>0;j--) d[j] = d[j-1];
                d[0] = ang;
                break;
            }
        }
    }
    for(int i=9;i>=1;i--){
        hap += d[i].x*(ll)i;
    }
    printf("%lld",hap);
    return 0;
}
