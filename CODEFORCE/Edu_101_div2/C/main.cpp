#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int t;
int n,k;
int a[200100];
tp h[200100];
bool f(){
    sort(h+2,h+n);
    for(int i=n-1;i>1;i--){
        int y,x; tie(y,x) = h[i];
        a[x] = max(max(0,max(a[x-1],a[x+1])) - k+1, y);
        if(a[x]>=y+k) return false;
    }
    if(abs(a[1]-a[2])>=k) return false;
    if(abs(a[n]-a[n-1])>=k) return false;
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) a[i] = -1;
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            h[i] = tp(x,i);
        }
        a[1] = get<0>(h[1]); a[n] = get<0>(h[n]);

        if(f()) printf("YES\n");
        else printf("NO\n");
        //for(int i=1;i<=n;i++) printf("[%d]",a[i]);
    }
    return 0;
}
