#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int chk[1<<21];
pair<int,int> path[1<<21];
vector<int> a[30];
queue<int> q;
void monkey_move(int x,int cur){
    int tmp = 0;
    for(int i=0;i<n;i++){
        if(x&(1<<i)){
            for(int j=0;j<a[i].size();j++){
                tmp |= (1<<a[i][j]);
            }
        }
    }
    if(chk[tmp] != cnt){
        chk[tmp] = cnt;
        path[tmp] = make_pair((x|(1<<cur)),cur);
        q.push(tmp);
    }
    return;
}
void print_dap(int x){
    if(x==((1<<n)-1)){
        return;
    }
    print_dap(path[x].first);
    q.push(path[x].second);
}
int main(){
    int x,y;
    while(1){
        ++cnt;
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++) a[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d %d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        chk[(1<<n)-1] = cnt;
        q.push((1<<n)-1);
        bool dap = false;
        while(!q.empty()){
            x = q.front(); q.pop();
            if(x==0) {
                dap = true;
                break;
            }
            for(int i=0;i<n;i++)
                if(x&(1<<i))
                    monkey_move((x^(1<<i)),i);
        }
        while(!q.empty()) q.pop();
        if(dap) {
            print_dap(0);
            printf("%d: ",q.size());
            while(!q.empty()){
                printf("%d ",q.front());
                q.pop();
            }
            puts("");
        }
        else printf("Impossible\n");
    }
    return 0;
}
