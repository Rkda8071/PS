#include<bits/stdc++.h>
using namespace std;

char a[110][11];
int n,dap,cnt[27],chk[27];
vector<int> p[27];
void fin(int x,int s,int e){
    if(x==11) return;
    for(int i=s;i<e;i++){
        if(a[i][x] == NULL) continue;
        if(a[i][x]!=a[i+1][x]){
            p[a[i+1][x]-'a'].push_back(a[i][x]-'a'); // i보다 p[i][1~m]이 크다
            ++cnt[a[i][x]-'a'];
            if(s<i) fin(x+1,s,i);
            s = i+1;
        }
    }
    if(s<e) fin(x+1,s,e);
}
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=10;j++) a[i][j] = 0;
    for(int i=0;i<26;i++) {
        p[i].clear();
        cnt[i] = 0;
    }
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
}
int main(){
    int t = 2;
    //scanf("%d",&t); ++t;
    while(--t){
        init();
        fin(1,1,n);
        for(int i=1;i<=n;i++){
            for(int j=1;a[i][j]!=NULL;j++){
                if(chk[a[i][j]-'a']!=t){
                    chk[a[i][j]-'a'] = t;
                }
            }
        }
        dap = 0;
        queue<int> q;
        stack<int> s;
        for(int i=0;i<26;i++)
            if(chk[i]==t && !cnt[i]) q.push(i);
        while(!q.empty()){
            int x = q.front(); q.pop();
            s.push(x);
            if(q.size()>=1) dap = 1;
            for(int i=0;i<p[x].size();i++){
                if(--cnt[p[x][i]] == 0)
                    q.push(p[x][i]);
            }
        }
        for(int i=0;i<26;i++) if(cnt[i]) dap = 2;
        if(!dap){
            while(!s.empty()){
                printf("%c",s.top()+'a');
                s.pop();
            }
        }
        else if(dap==1) printf("?");
        else printf("!");
        puts("");
    }
    return 0;
}
