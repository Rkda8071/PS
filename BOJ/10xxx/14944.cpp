#include<bits/stdc++.h>
using namespace std;
int n,m,sum[10010],a[10010],ans = 1e9;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }

    while(m--){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(x>y) swap(x,y);
        ans = min({ans, z + sum[n] - a[x+1] + sum[n] - sum[y]});

        // sum[n] + z

        // x로 들어간다
            // y 오른쪽 z + sum[n] - a[x+1] + sum[n] - sum[y]
            // y 왼쪽   
                // sum[x] + z + sum[y] + sum[n]
                // sum[x] + z + sum[y] + sum[x] + z + sum[n] - sum[y]

        // y로 들어간다
            // x 오른쪽으로 나온다

            // x 왼쪽으로 나온다
    }
    printf("%d",ans);
}