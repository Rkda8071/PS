#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
typedef long long ll;
tp a[100010];
ll b[200010];
int m,n;
void init(){
    scanf("%d %d",&n,&m);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d %d",&x,&y);
        a[i] = tp(x,y);
    }
    sort(a+1,a+n+1,greater<tp>());
    int chk = 0;
    for(int i=1;i<n+m;i++){
        if(i<=n) chk = (chk ^ get<1>(a[i]));
        if(i>=m){
            b[i-m+1] = (ll)chk;
            chk = (chk ^ get<1>(a[i-m+1]));
        }
    }
    for(int i=m+1;i<=n;i++){
        b[i] += b[i-m];
    }
}
int main(){
    init();
    int t,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&x,&y);
        //x개의 팀, y명의 출제진
        printf("%lld\n",b[(x-1)*m+y+1]-((y+1-m>0)?b[y+1-m]:0LL));
    }
    return 0;
}
