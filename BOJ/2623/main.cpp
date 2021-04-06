#include<bits/stdc++.h>
using namespace std;
int n,m,chk[1010];
vector<int> a[1010];
queue<int> q,d;
void init(){
    int x,y,z;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&x,&y);
        for(int i=1;i<x;i++){
            scanf("%d",&z);
            a[y].push_back(z);
            chk[z]++; y=z;
        }
    }
}
int main(){
    init();
    for(int i=1;i<=n;i++) if(!chk[i]) q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        d.push(x);
        for(int i=0;i<a[x].size();i++)
            if(!--chk[a[x][i]])
                q.push(a[x][i]);
    }
    if(d.size() != n) printf("0");
    else{
        while(!d.empty()){
            printf("%d\n",d.front());
            d.pop();
        }
    }
    return 0;
}
