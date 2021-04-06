#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,m,k,idx;
char dap[40100];
tp a[210];
int main(){
    int y,x,yy,xx;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;i++) scanf("%*d %*d");
    for(int i=0;i<k;i++){
        scanf("%d %d",&y,&x);
        a[i] = tp(y,x);
    }
    sort(a,a+k);
    for(int i=1;i<=n;i++) dap[++idx] = 'U';
    for(int i=1;i<=m;i++) dap[++idx] = 'L';
    y=x=1;
    for(int i=0;i<k;i++){
        tie(yy,xx) = a[i];
        for(int i=max(y,yy)-min(y,yy);i>0;i--) dap[++idx] = 'D';
        for(int i=max(x,xx)-min(x,xx);i>0;i--)
            dap[++idx] = (x>xx)?'L':'R';
        y = yy; x = xx;
    }
    printf("%d\n",idx);
    for(int i=1;i<=idx;i++) printf("%c",dap[i]);
    return 0;
}
