#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y1,y2;
    bool operator<(const A &r) const{
        return y1<r.y1 || (y1==r.y1 && x<r.x);
    }
};
int n,sy,ex;
int x,y,z;
int main(){
    scanf("%d %d %d",&n,&sy,&ex);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&z);
        a[i] = {x,y,z};
    }

}
