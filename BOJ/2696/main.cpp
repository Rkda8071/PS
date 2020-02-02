#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x;
        priority_queue<int> l;
        priority_queue<int,vector<int>,greater<int> > r;
        queue<int> dap;
        scanf("%d %d",&n,&m);
        dap.push(m);
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
            dap.push(m);
        }
        printf("%d\n",dap.size());
        n = 0;
        while(!dap.empty()){
            if(n++ == 10) {puts(""); n=1;}
            printf("%d ",dap.front()); dap.pop();
        }
        puts("");
    }
    return 0;
}
