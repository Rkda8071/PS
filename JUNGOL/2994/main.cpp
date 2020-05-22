#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
struct A{
    int x,y1,y2;
    bool operator<(const A &r)const{
        return x<r.x;
    }
}a[100100];
set<tp> s;
int n,sy,ex;
int main(){
    int x,y,z;
    scanf("%d %d %d",&n,&sy,&ex);

    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&x,&y,&z);
        a[i] = {x,y,z};
    }
    sort(a+1,a+n+1);
    s.insert(tp(sy,0));
    for(int i=1;i<=n;i++){
        int m1,m2; m1 = m2 = 2000000000;
        auto j = s.lower_bound(tp(a[i].y1,0));
        auto tmp = s.begin();
        for(;j!=s.end();j=tmp){
            tie(y,x) = *j;
            if(y>a[i].y2) break;
            m1 = min(m1,y-a[i].y1+x);
            m2 = min(m2,a[i].y2-y+x);
            tmp = j; ++tmp;
            s.erase(j);
        }
        if(m1!=2000000000) s.insert(tp(a[i].y1,m1));
        if(m2!=2000000000) s.insert(tp(a[i].y2,m2));
    }

    int mini = 2000000000;
    vector<int> dap;

    for(auto j=s.begin();j!=s.end();j++)
        if(mini>get<1>(*j)) mini = get<1>(*j);
    for(auto j=s.begin();j!=s.end();j++)
        if(mini==get<1>(*j)) dap.push_back(get<0>(*j));

    dap.erase(unique(dap.begin(),dap.end()),dap.end());

    printf("%d\n%d ",mini+ex,dap.size());
    for(int i=0;i<dap.size();i++) printf("%d ",dap[i]);

    return 0;
}
