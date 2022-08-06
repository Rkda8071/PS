#include<bits/stdc++.h>
using namespace std;
int n,m,p[200010],r;
bool ans[200010];
vector<int> a[200010];
stack<int> s;
int fin(int x){
    if(p[x] == x) return x;
    return p[x] = fin(p[x]);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0,x,y;i<m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0,x;i<n;i++){
        scanf("%d",&x);
        s.push(x);
        r = x;
    }

    for(int i=n-1;i>=0;i--){
        int x = s.top(); s.pop();
        for(int y : a[x]){
            
        }
    }
}