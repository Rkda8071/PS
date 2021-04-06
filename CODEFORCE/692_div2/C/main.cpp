#include<bits/stdc++.h>
using namespace std;
int t;
int a[100100];
int b[100100];
int main(){
    scanf("%d",&t);
    while(t--){
        int n,m,dap=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) b[i]=a[i]=0;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            a[x] = y;
            b[y] = x;
        }
        queue<int> q;
        set<int> s;
        for(int i=1;i<=n;i++) if(a[i]) s.insert(i);
        for(int i=1;i<=n;i++){
            if(a[i]){
                if(i == a[i]){
                    b[a[i]] = 0;
                    a[i] = 0;
                    s.erase(i);
                }
                else{
                    q.push(i);
                    while(!q.empty()){
                        int x = q.front(); q.pop();
                        if(b[x] && a[a[x]]){
                            continue;
                        }else{
                            dap++;
                            s.erase(x);
                            if(a[a[x]]) q.push(a[x]);
                            if(b[x]) q.push(b[x]);
                            b[a[x]] = 0;
                            a[x] = 0;
                        }
                    }
                }
            }
        }
        if(s.size()) dap+=s.size()+1;
        printf("%d\n",dap);
    }
    return 0;
}
