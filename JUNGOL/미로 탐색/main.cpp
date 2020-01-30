#include<bits/stdc++.h>
using namespace std;
vector<int> a[100100];
queue<int> q;
int chk[100100];
int cnt,n,m;
void f(int x){
    if(chk[x]==0){
        chk[x] = 1;
        q.push(x);
        if(++cnt == n) return;
        sort(a[x].begin(),a[x].end());
    }
    int k = a[x].size();
    for(int i=0;i<k;i++){
        if(chk[a[x][i]] == 0){
            f(a[x][i]);
        }
    }
    return;
}
int main(){
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    f(1);
    while(!q.empty()){
        printf("%d ",q.front());
        q.pop();
    }
    return 0;
}
