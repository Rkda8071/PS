#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a[200010];
int col[200010],p[200010],r[200010],cnt;
int xx[200010],yy[200010];
queue<int> q;
void bfs(int x){
    int y = r[col[x]]; p[x] = 0;
    if(x==y) return;
    int i,j,c1,c2,cnt1,cnt2,ang;
    xx[1] = x; yy[1] = y;
    cnt1 = cnt2 = c1 = c2 = 1;
    i = j = ang = 0;
    while(1){
        while(1){
            while(a[xx[c1]].size() == i){
                if(++c1 > cnt1) {ang = 1; break;}
                i = 0;
            }
            if(ang) break;
            if(p[a[xx[c1]][i]] == 0){
                swap(a[xx[c1]][i],a[xx[c1]][a[xx[c1]].size()-1]);
                a[xx[c1]].pop_back();
            } else break;
        }
        while(1){
            while(a[yy[c2]].size() == j){
                if(++c2 > cnt2) {ang = 2; break;}
                j = 0;
            }
            if(ang) break;
            if(p[a[yy[c2]][j]] == 0){
                swap(a[yy[c2]][j],a[yy[c2]][a[yy[c2]].size()-1]);
                a[yy[c2]].pop_back();
            } else break;
        }
        if(ang) break;
        xx[++cnt1] = a[xx[c1]][i++];
        yy[++cnt2] = a[yy[c2]][j++];
    }

    if(ang == 2) swap(x,y);
    if(r[col[x]] == x) r[col[x]] = y;
    int cur = col[x]; q.push(x); //x가 무게가 작은놈
    col[x] = ++cnt;
    r[cnt] = x;
    while(!q.empty()){
        x = q.front(); q.pop();
        col[x] = cnt;
        for(int i=0;i<a[x].size();i++)
            if(col[a[x][i]] == cur)
                q.push(a[x][i]);
    }
}
int main(){
    int x,y,z;
    scanf("%d %d",&n,&m);
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        a[x].push_back(i);
        p[i] = x;
    }
    r[0] = 1;
    ++m;
    while(--m){
        scanf("%d %d %d",&x,&y,&z);
        if(col[x]==col[y]){
            printf("YES\n");
            if(z) bfs(x);
        }else{
            printf("NO\n");
            if(z) bfs(y);
        }
    }
    return 0;
}
