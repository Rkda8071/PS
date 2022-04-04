#include<bits/stdc++.h>
using namespace std;
tuple<int,int> tp;
int n,q;
tp a[200100];
int l[200100],r[200100];
int lc[200100],rc[200100];
void init(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&y,&x);
        a[i] = tp(x,y);
    }
    sort(a+1,a+n+1);
    lc[1] = get<1>(a[1]);
    rc[n] = get<1>(a[n]);

    for(int i=2;i<=n;i++){
        int x,y,z=get<1>(a[i-1]);
        tie(x,y) = a[i];
        l[i] = (x-z)*lc[i-1];
        lc[i] = lc[i-1] + y;
    }

    for(int i=n-1;i>=1;i--){
        int x,y,z=get<1>(a[i+1]);
        tie(x,y) = a[i];
        r[i] = (z-x)*rc[i+1];
        rc[i] = rc[i+1] + y;
    }
}
int main(){
    init();
    while(q--){
        int x;
        scanf("%d",&x);
        sort(a+1,a+n+1,tp(x,0));
    }

}
