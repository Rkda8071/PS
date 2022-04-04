#include<bits/stdc++.h>
using namespace std;
int n;
int a[2010],d[4010],p[4010];
void solve(){
    int r,c;
    r = c = 0;
    for(int i=1;i<=2*n+1;i++){
        if(r>=i)
            p[i] = min(r-i,p[c*2-i]);
        else
            p[i] = 0;
        while(i+p[i]+1 <= 2*n+1){
            if(d[i+p[i]+1] == d[i-p[i]-1])
                p[i] += 1;
            else
                break;
        }
        if(i+p[i] > r){
            r = i+p[i];
            c = i;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    d[1] = 0;
    for(int i=1;i<=n;i++){
        d[i*2] = a[i];
        d[i*2+1] = 0;
    }
    solve();

    int t;
    scanf("%d",&t);
    while(t--){
        int s,e;
        scanf("%d %d",&s,&e);
        if(p[s+e] >= e-s) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
