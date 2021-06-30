#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll d[200100];
vector<ll> a[4];
int chk[200100];

void init(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<4;i++){
        ll x;
        scanf("%lld",&x);
        a[i].push_back(x);
    }
    for(int i=0;i<n;i++){
        char x;
        ll y;
        scanf(" %c %lld",&x,&y);
        a[x-'A'].push_back(y);
    }
    for(int i=0;i<4;i++)
        sort(a[i].begin()+1,a[i].end(),greater<int>());
    for(int i=0;i<4;i++)
        for(int j=1;j<a[i].size();j++)
            a[i][j] += a[i][j-1];
}
void init_d(){
    int l=a[0].size()-1, r=a[1].size()-1;
    while(l || r){
        d[l+r] = a[0][l] * a[1][r];
        chk[l+r] = r;
        if(l==0)
            --r;
        else if(r==0)
            --l;
        else{
            if(a[0][l-1]*a[1][r]>a[0][l]*a[1][r-1])
                --l;
            else
                --r;
        }
    }
    d[0] = a[0][0] * a[1][0];
    chk[0] = 0;
}
void solve(){
    ll maxim = 0;

    int l=a[2].size()-1, r=a[3].size()-1,dapr=0,dapl=0;
    while(l || r){
        ll ang = a[2][l] * a[3][r]; //l+r
        if(k>=l+r && d[k-(l+r)]){
            if(maxim<d[k-(l+r)]*ang){
                maxim = d[k-(l+r)]*ang;
                dapr=r; dapl=l;
            }
        }
        if(l==0)
            --r;
        else if(r==0)
            --l;
        else{
            if(a[2][l-1]*a[3][r]>a[2][l]*a[3][r-1])
                --l;
            else
                --r;
        }
    }
    ll ang = a[2][l] * a[3][r]; //l+r
    if(k>=l+r && d[k-(l+r)]){
        if(maxim<d[k-(l+r)]*ang){
            maxim = d[k-(l+r)]*ang;
            dapr=r; dapl=l;
        }
    }
    int ang2 = k-(dapr+dapl);

    for(int i=1;i<=ang2-chk[ang2];i++)
        printf("A %lld\n",a[0][i]-a[0][i-1]);
    for(int i=1;i<=chk[ang2];i++)
        printf("B %lld\n",a[1][i]-a[1][i-1]);
    for(int i=1;i<=dapl;i++)
        printf("C %lld\n",a[2][i]-a[2][i-1]);
    for(int i=1;i<=dapr;i++)
        printf("D %lld\n",a[3][i]-a[3][i-1]);
}
int main(){
    init();
    init_d();
    solve();

    return 0;
}
