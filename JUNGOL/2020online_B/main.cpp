#include<bits/stdc++.h>
using namespace std;
char a[2000100];
int cnt[30],n,chk = -1,m;
int solve(){
    for(int i=0;i<26;i++){
        if(cnt[i]%2){
            if(chk == -1) chk = i;
            else return 0; // NOT POSSIBLE
        }
    }
    if(m<=2)
}
int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    for(int i=1;i<=n;i++) if(cnt[a[i]-'A']++ == 0) ++m;
    int res = solve();
    if(res == 0) printf("NOT POSSIBLE");
    else if(res == 1)
    else
    return 0;
}
