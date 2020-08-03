#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k;
ll a[100100],d[100100],mini = 200000000,cnt;
int main(){
    scanf("%d %lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        cnt = 0;
        for(int j=1;j<i;j++)
            if(a[i-j] != a[i]-j*k) cnt++;
        for(int j=1;j<=n-i;j++)
            if(a[i+j] != a[i]+j*k) cnt++;
        mini = min(cnt,mini);
    }
    printf("%lld",mini);
    return 0;
}
