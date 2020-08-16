#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
int n,m;
int d[50010];
queue<int> dap;
//priority_queue<tp,vector<tp>,greater<tp> > pq;
int fin(int x){
    if(d[x] == x) return x;
    return d[x] = fin(d[x]);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) d[i] = i;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        x = fin(x); y = fin(y);
        if(x!=y) dap.push(i);
        d[x] = y;
    }
    printf("%d\n",dap.size());
    while(!dap.empty()){
        printf("%d ",dap.front()); dap.pop();
    }
    return 0;
}
