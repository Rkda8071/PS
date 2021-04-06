#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[4040][5],n;
map<int,int> m;
vector<int> l,r;
ll dap;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=4;j++) scanf("%d",&a[i][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l.push_back(a[i][1]+a[j][2]);
            r.push_back(a[i][3]+a[j][4]);
        }
    }
    sort(r.begin(),r.end());
    for(int i=0;i<l.size();i++){
        int x = upper_bound(r.begin(),r.end(),-l[i]) - r.begin();
        int y = lower_bound(r.begin(),r.end(),-l[i]) - r.begin();
        if(x>0) --x;
        if(r[x] == r[y] && r[x] == -l[i])
            dap += (ll)(x-y+1);
    }
    printf("%lld",dap);
    return 0;
}
