#include<bits/stdc++.h>
using namespace std;
int n,a[300010];
pair<int, int> d[300010];

void init(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0,x;i<n;i++){
        scanf("%d",&x);
        d[i] = make_pair(x,a[i]);
    }
}
int main(){
    setbuf(stdout, NULL);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        init();
        sort(d,d+n);
        long long ans = 0LL;
        for(int i=0;i<n;i++)
            ans += (long long)(abs(d[i].second - a[i]));
        printf("Case #%d\n%lld\n",tt,ans);
    }
    return 0;
}

