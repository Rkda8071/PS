#include<bits/stdc++.h>
using namespace std;
vector<int> a[32010];
int chk[100010],n,m;
queue<int> q;
void init(){
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        chk[y]++;
        a[x].push_back(y);
    }
}
int main(){
    init();
    for(int i=1;i<=n;i++) if(!chk[i]) q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        printf("%d ",x);
        for(int i=0;i<a[x].size();i++){
            if(!--chk[a[x][i]]){
                q.push(a[x][i]);
            }
        }
    }
    return 0;
}
