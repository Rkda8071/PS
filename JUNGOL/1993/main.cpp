#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
queue<tp> q;
int n,score[4][4];
char in[20][20];
int a[20][20];
int d[21][1<<11],chk[1<<11];

void init(){
    for(int i=0;i<3;i++){
        int cur = 100 - 30*i;
        for(int j=0;j<3;j++){
            score[i][j] = cur - (30-(10*i))*j;
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf(" %s",in[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(in[i][j] == 'F') a[i][j] = 3;
            else a[i][j] = in[i][j] - 'A';
        }
    }
}

int main(){
    init();
    q.emplace(0,0,0); // x,cur;
    while(!q.empty()){
        int x,cur,t;
        tie(x,cur,t) = q.front(); q.pop();
        if(cur == n){
            d[0][x] = max(d[0][x],t);
            continue;
        }
        if(cur+1<=n) {
            q.emplace(x|(1<<cur),cur+1,t + score[a[0][cur]][a[1][cur]]);
            q.emplace(x,cur+1,t);
        }
        if(cur+2<=n) q.emplace(x,cur+2,t + score[a[0][cur]][a[0][cur+1]]);
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            //for(int l=0;l<(1<<n);l++) chk[l] = -1;
            q.emplace(0,0,d[i-1][j]);
            while(!q.empty()){
                int x,cur,t;
                tie(x,cur,t) = q.front(); q.pop();
                //if(chk[x]<t) chk[x] = t;
                //else continue;
                if(cur == n){
                    d[i][x] = max(d[i][x],t);
                    continue;
                }
                for(int l=cur;l<n;l++){
                    if(!(j&(1<<l))){
                        if(i<n-1 && l+1<=n){
                            q.emplace(x|(1<<l),l+1,t + score[a[i][l]][a[i+1][l]]);
                            //q.emplace(x,l+1,t);
                        }
                        if(l+2<=n && !(j&(1<<(l+1)))) q.emplace(x,l+2,t + score[a[i][l]][a[i][l+1]]);
                        //break;
                    }
                }
                d[i][x] = max(d[i][x],t);
            }
        }
    }
    printf("%d",d[n-1][0]);
    return 0;
}
