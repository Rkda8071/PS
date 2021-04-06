#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll a[200200];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++) a[i] = 0LL;
        for(int i=1;i<=n;i++){
            int ang; scanf("%d",&ang);
            a[ang]++;
        }

    }
    return 0;
}
