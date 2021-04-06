#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],c[100100],cnt[100100],n,m;
vector<int> v[100100];
bool solve(){
    int chk=0,dap=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);

    for(int i=1;i<=n;i++){
        cnt[i] = 0;
        v[i].clear();
    }

    for(int i=1;i<=n;i++){
        if(v[b[i]].size() == 0){
            v[b[i]].push_back(i);
            cnt[b[i]]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            cnt[b[i]]++; dap++;
            v[b[i]].push_back(i);
        }
    }

    for(int i=m;i>=1;i--){
        if(--cnt[c[i]]<0){
            if(!chk) return false;
            else c[i] = chk;
        }else{
            dap--;
            int ang = v[c[i]][cnt[c[i]]];
            if(!cnt[c[i]]) {cnt[c[i]]++; dap++;}
            c[i] = ang;
            chk = ang;
        }
    }
    if(dap) return false;
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        if(solve()){
            printf("YES\n");
            for(int i=1;i<=m;i++) printf("%d ",c[i]);
            puts("");
        }else printf("NO\n");
    }
    return 0;
}

