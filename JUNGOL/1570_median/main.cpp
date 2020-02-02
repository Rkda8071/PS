#include<bits/stdc++.h>
using namespace std;
priority_queue<int> l;
priority_queue<int,vector<int>,greater<int> > r;
int main(){
    int n,m;
    int x,y;
    scanf("%d %d",&n,&m);
    printf("%d\n",m);
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=2;j++){
            scanf("%d",&x);
            if(x>m) r.push(x);
            else l.push(x);
        }
        if(l.size()>r.size()) {
            r.push(m);
            m = l.top(); l.pop();
        } else if(l.size()<r.size()){
            l.push(m);
            m = r.top(); r.pop();
        }
        printf("%d\n",m);
    }
    return 0;
}
