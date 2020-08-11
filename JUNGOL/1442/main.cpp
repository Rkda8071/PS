#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int> tp;
queue<tp> q;
int n,m;
ll d[12][1<<11];

int main(){
    scanf("%d %d",&n,&m);
    // i 에서 위아래로 세우면 1 좌우로 세우면 0
    // (위아래로 세우려면) 1을 넣으려면 앞에 1이 있거나 앞에 00이 있어야함
    q.emplace(0,2); q.emplace(1,1);
    while(!q.empty()){
        int x,cur;
        tie(x,cur) = q.front(); q.pop();
        if(cur == m){
            d[0][x] += 1L;
            continue;
        }
        if(cur+1 <= m) // 1세울 때
            q.emplace(x|(1<<cur),cur+1);
        if(cur+2 <= m) // 0세울 때
            q.emplace(x,cur+2);
    }

    for(int i=1;i<n;i++){
        // 1. 밑 층에서 했던 것들 q에다가 다 집어 넣기
        // 2. q 돌리기
        // 잇힝
        for(int j=0;j<(1<<m);j++){
            if(d[i-1][j]){
                // f = j , t = d[i-1][j];
                q.emplace(0,0);
                while(!q.empty()){
                    int x,cur;
                    tie(x,cur) = q.front(); q.pop();
                    if(cur == m){
                        d[i][x] += d[i-1][j];
                        continue;
                    }
                    int chk = 0;
                    for(int l=cur;l<m;l++){
                        if(!(j&(1<<l))){ //비어있음?
                            if(l+1 <= m)// 1세울 때
                                q.emplace(x|(1<<l),l+1);
                            if(l+2 <= m && !(j&(1<<(l+1)))) // 0세울 때
                                q.emplace(x,l+2);
                            chk = 1;
                            break;
                        }
                    }
                    if(chk) continue;
                    else d[i][x] += d[i-1][j];
                }
            }
        }
    }
    printf("%lld",d[n-1][0]);
    return 0;
}
