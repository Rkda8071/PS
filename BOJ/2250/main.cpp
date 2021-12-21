#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
p a[10010];
int n, cnt;
int l[10010],r[10010],chk[10010],root;
void dfs(int lev,int id){
    if(id==-1) return;
    dfs(lev+1,a[id].first);
    ++cnt;
    l[lev] = min(l[lev],cnt);
    r[lev] = max(r[lev],cnt);
    dfs(lev+1,a[id].second);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        chk[y] = chk[z] = 1;
        a[x] = p(y,z);
        l[i] = 2000000000;
    }
    for(int i=1;i<=n;i++){
        if(chk[i] == 0){
            dfs(1,i);
            break;
        }
    }
    int maxim=0,m;
    for(int i=1;i<=n;i++){
        if(r[i] == 0) break;
        if(r[i] - l[i] + 1> maxim){
            maxim = r[i] - l[i] + 1;
            m = i;
        }
    }
    printf("%d %d",m,maxim);
    return 0;
}
