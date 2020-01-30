#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*ll a[1000100];
int main(){
    int n,m,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i] += a[i-1];
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        printf("%lld\n",a[y]-a[x-1]);
    }
    return 0;
}
*/

ll a[1010][1010];
int main(){
    int n,m;
    int x1,y1,x2,y2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        --x1; --y1;
        printf("%lld\n",a[y2][x2] - a[y1][x2] - a[y2][x1] + a[y1][x1]);
    }
    return 0;
}
