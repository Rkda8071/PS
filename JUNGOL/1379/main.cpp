/*#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<int> a[300010],dap;
int ord[300100],bak[300100],r[300100],chk;
int dfs(int x){
    bak[x] = ord[x] = ++cnt;
    for(int i=0;i<a[x].size();i++){
        if(!ord[a[x][i]]){
            r[a[x][i]] = x;
            bak[x] = min(bak[x],dfs(a[x][i]));
        } else if(r[x] != a[x][i])
            bak[x] = min(bak[a[x][i]],bak[x]);

        if(i==0 && x==1 && cnt != n) dap.push_back(1);
    }
    return bak[x];
}

int main(){
    scanf("%d %d",&n,&m);
    int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1);
    for(int i=2;i<=n;i++){
        chk = 0;
        for(int j=0;j<a[i].size();j++){
            if(i == r[a[i][j]]){ // 자식일때
                // 모든 자식들이 ord[i] <= bak[a[i][j]]
                if(ord[i] <= bak[a[i][j]]){
                    chk = 1;
                    break;
                }
            }
        }
        if(chk==1) dap.push_back(i);
    }
    printf("%d\n",dap.size());
    for(int i=0;i<dap.size();i++) printf("%d ",dap[i]);
    //if(dap.size() == 0) printf("-1");
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<int> a[10010],dap;
int ord[10100],bak[10100],r[10100],childcnt[10100];
int dfs(int x){
    bak[x] = ord[x] = ++cnt;
    for(int i=0;i<a[x].size();i++){
        if(!ord[a[x][i]]){
            r[a[x][i]] = x;
            int res = dfs(a[x][i]);
            if(ord[x] <= res) childcnt[x]++;
            bak[x] = min(bak[x],res);
        } else if(r[x] != a[x][i])
            bak[x] = min(ord[a[x][i]],bak[x]);
    }
    return bak[x];
}
int main(){
    scanf("%d %d",&n,&m);
    int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!ord[i]){
            dfs(i);
            childcnt[i]--;
        }
    }
    for(int i=1;i<=n;i++)
        if(childcnt[i]>0) dap.push_back(i);

    printf("%d\n",dap.size());
    for(int i=0;i<dap.size();i++) printf("%d ",dap[i]);
    //if(dap.size() == 0) printf("-1");
    return 0;
}
