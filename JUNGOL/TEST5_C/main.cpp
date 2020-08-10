#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
vector<int> a[100100];
queue<tp> q;
int n,m,s,e;
int ss[100100],ee[100100];
int fin(int x,int d,int pre){
    q.emplace(x,0,0);
    while(!q.empty()){
        tie(x,d,pre) = q.front(); q.pop();
        for(int i=0;i<a[x].size();i++){
            if(pre == a[x][i]) continue;
            q.emplace(a[x][i],d+1,x);
        }
    }
    return x;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    s = fin(1,0,0);
    e = fin(s,0,0);

    return 0;
}
