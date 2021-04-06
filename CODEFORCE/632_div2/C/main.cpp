#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct A{
    ll s;
    int id;
    bool operator<(const A &r)const{
        return s<r.s || (s==r.s && id<r.id);
    }
}a[200100];
ll x,dap;
int y,d[200100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) d[i] = n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        a[i] = {x+a[i-1].s,i};
        if(!x) d[i]=i-1;// --dap;}
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int j = i;
        while(j<n && a[i].s==a[j+1].s) ++j;
        if(a[i].s==0)
            if(d[1]>a[i].id-1)
                d[1] = a[i].id-1;
        for(int l=i;l<j;l++)
            if(d[a[l].id+1]>a[l+1].id-1)
                d[a[l].id+1] = a[l+1].id-1;

        i = j;
    }
    int mini = n;
    for(int i=n;i>=1;i--){
        if(d[i]>mini) d[i] = mini;
        //mini = min(mini,d[i]-1);
        else if(d[i]<mini) mini = d[i];
    }
    for(int i=1;i<=n;i++){
        dap += (ll)(d[i]-i+1);
    }
    printf("%lld",dap);
    return 0;
}
