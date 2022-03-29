#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[1010],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[0] = max(a[0],a[i]);
    }
    for(int i=1;i<=n;i++)
        if(a[i-1]>a[i]) ans+=a[i-1]-a[i];
    printf("%lld",ans);
    return 0;
}

/*int n;
ll a[1001],d[1010][1010],m[1010][1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        m[i][i] = a[i];
    }
    for(int k=1;k<n;k++){
        for(int i=1;i<=n-k;i++){
            ll x,y;
            if(a[i] > m[i+1][i+k]) x = d[i+1][i+k] + abs(a[i]-m[i+1][i+k]);
            else x = d[i+1][i+k] + max(0LL,a[i+1]-a[i]);

            if(a[i+k] > m[i][i+k-1]) y = d[i][i+k-1] + abs(a[i+k]-m[i][i+k-1]);
            else y = d[i][i+k-1] + max(0LL,a[i+k-1]-a[i+k]);

            d[i][i+k] = min(x,y);
            m[i][i+k] = max(m[i][i+k-1],m[i+1][i+k]);
        }
    }
    printf("%lld",d[1][n]);
    return 0;
}
*/
