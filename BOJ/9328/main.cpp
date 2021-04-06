#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,m,chk[110][110];
int yyy[4] = {0,0,1,-1}, xxx[4] = {1,-1,0,0};
char a[110][110];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int dap = 0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf(" %s",a[i]+1);
        for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) chk[i][j] = 0;
        vector<tp> door[30];
        int key[30] = {0};
        char imsi[30] = {0};
        queue<tp> q;
        scanf("%s",imsi+1);
        for(int i=1;imsi[i]!=NULL;i++){
            if(imsi[i] == '0') break;
            else key[imsi[i]-'a'] = 1;
        }
        for(int i=0;i<=n+1;i++) a[i][m+1] = a[i][0] = '.';
        for(int i=0;i<=m+1;i++) a[n+1][i] = a[0][i] = '.';
        q.emplace(0,0);
        // init 다 끝남
        while(!q.empty()){
            int y,x;
            tie(y,x) = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int yy = y+yyy[i], xx = x+xxx[i];
                if(yy>=0 && yy<=n+1 && xx>=0 && xx<=m+1){
                    if(a[yy][xx] == '*' || chk[yy][xx]) continue;
                    chk[yy][xx] = 1;
                    if('a' <= a[yy][xx] && a[yy][xx] <= 'z'){ // key 인가?
                        if(!key[a[yy][xx] - 'a']){
                            key[a[yy][xx] - 'a'] = 1;
                            for(tp ang : door[a[yy][xx]-'a'])
                                q.push(ang);
                        }
                        q.emplace(yy,xx);
                    } else if('A' <= a[yy][xx] && a[yy][xx] <= 'Z'){ // door 인가?
                        if(!key[a[yy][xx] - 'A'])
                            door[a[yy][xx]-'A'].push_back(tp(yy,xx));
                        else q.emplace(yy,xx);
                    } else{
                        q.emplace(yy,xx);
                        if(a[yy][xx] == '$') dap++;
                    }
                }
            }
        }
        printf("%d\n",dap);
    }
    return 0;
}
