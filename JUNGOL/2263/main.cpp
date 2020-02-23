#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,n;
    bool operator<(const A &r)const{
        return v<r.v;
    }
    bool operator<(int r)const{
        return v<r;
    }
}a[100010];
char ang[50];
int chk[100010],path[100010],b[100010];
vector<int> v[100010];
queue<int> q;
int main(){
    int n,k,t;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",ang);
        a[i].v = stoi(ang,nullptr,2);
        a[i].n = i;
    }
    sort(a+2,a+n+1);
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            int tmp = a[i].v ^ (1<<j);
            int x = lower_bound(a+i+1,a+n+1,tmp) - a;
            if(a[x].v==tmp){
                v[i].push_back(x);
                v[x].push_back(i);
            }
        }
    }
    scanf("%d",&t);
    int w;
    q.push(1); chk[1] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        //if(a[x].n == w) break;
        for(int i=0;i<v[x].size();i++){
            if(!chk[v[x][i]]){
                q.push(v[x][i]);
                chk[v[x][i]] = 1;
                path[v[x][i]] = x;
            }
        }
    }
    for(int i=1;i<=n;i++) b[a[i].n] = i;
    for(int l=1;l<=t;l++){
        scanf("%d",&w);
        w = b[w];
        stack<int> s;
        while(w!=0){
            s.push(a[w].n);
            if(!path[w] && w!=1) s.push(-1);
            w = path[w];
        }
        if(s.top() == -1){
            printf("-1");
            while(!s.empty()) s.pop();
        }
        while(!s.empty()){
            printf("%d ",s.top());
            s.pop();
        }
        puts("");
    }
    return 0;
}
