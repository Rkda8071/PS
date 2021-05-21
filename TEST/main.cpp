#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[30],cnt[30];
int dap[10];
void f(int x){
    if(x==m+1){
        for(int i=1;i<=m;i++)
            printf("%c",dap[i] + 'a');
        puts("");
        return;
    }
    for(int i=0;i<26;i++){
        if(cnt[i]<a[i]){
            cnt[i]++;
            dap[x] = i;
            f(x+1);
            cnt[i]--;
            dap[x] = 0;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        char x;
        scanf(" %c",&x);
        a[x-'a']++;
    }
    //dap[0] = 0;
    f(1);
}
