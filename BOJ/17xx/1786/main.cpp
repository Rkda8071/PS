#include<bits/stdc++.h>
using namespace std;
char t[1001000],p[1001000];
int n,m,kmp[1001000];
vector<int> dap;
int main(){

    //scanf("%[^\n]s",t+1);
    while(1){
        char ang;
        scanf("%c",&ang);
        if(ang == '\n') break;
        t[++n] = ang;
    }
    scanf("%[^\n]s",p+1);

    n = strlen(t+1);
    m = strlen(p+1);

    int k = 0;
    for(int i=2;i<=m;i++){
        while(1){
            if(p[k+1] == p[i]){
                kmp[i] = ++k;
                break;
            }else{
                if(k==0) break;
                k = kmp[k];
            }
        }
    }

    int cur = 0;
    for(int i=1;i<=n;i++){
        while(1){
            if(t[i] == p[cur+1]){
                cur++;
                break;
            }else{
                if(cur==0) break;
                cur = kmp[cur];
            }
        }
        if(cur==m)
            dap.push_back(i-m+1);
    }
    printf("%d\n",dap.size());
    for(int i=0;i<dap.size();i++)
        printf("%d ",dap[i]);
    return 0;
}
