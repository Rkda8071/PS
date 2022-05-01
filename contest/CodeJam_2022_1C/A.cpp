#include<bits/stdc++.h>
using namespace std;
int n,ii;
char a[110][11],b[26],ans[10010];
int cnt[26],m[110],chk[26];
vector<int> c[26];
bool init(){
    scanf("%d",&n);
    ii = 0;
    for(int i=1;i<=n;i++) scanf(" %s",a[i]);
    for(int i=1;i<=n;i++) m[i] = strlen(a[i]);
    for(int i=0;i<26;i++) chk[i] = cnt[i] = 0;
    for(int i=0;i<26;i++) b[i] = 0;
    for(int i=0;i<10010;i++) ans[i] = 0;
    for(int i=0;i<26;i++) c[i].clear();
    for(int i=1;i<=n;i++){
        char from, to;
        from = a[i][0]; to = a[i][m[i]-1];
        if(to==from){
            c[to-'A'].push_back(i);
            continue;
        }
        if(b[to-'A']) return false;
        b[to-'A'] = from;
    }
    return true;
}

void dfs(char x){
    char from, to, chkchk=0;
    for(auto i : c[x-'A']){
        for(int j=0;j<m[i];j++)
            ans[ii+j] = a[i][j];
        ii += m[i];
    }
    for(int i=1;i<=n;i++){
        from = a[i][0]; to = a[i][m[i]-1];
        if(from == x && to != x){
            chkchk = to;
            for(int j=0;j<m[i];j++)
                ans[ii+j] = a[i][j];
            ii += m[i];
            break;
        }
    }
    if(chkchk == 0) return;
    dfs(chkchk);
}
bool solve(){
    if(!init()) return false;
    for(int i=0;i<26;i++){
        if(b[i] == 0){
            dfs('A'+i);
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++) sum += m[i];
    if(ii != sum) return false;
    for(int i=0;i<ii-1;i++){
        if(chk[ans[i+1]-'A']) return false;
        if(ans[i] != ans[i+1]){
            chk[ans[i]-'A'] = 1;
        }
    }
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        printf("Case #%d: ",tt);
        if(solve())
            for(int i=0;i<ii;i++)
                printf("%c",ans[i]);
        else
            printf("IMPOSSIBLE");
        puts("");
    }
}