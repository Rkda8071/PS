#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,m;
int d[15][1<<15];

int main(){
    scanf("%d %d",&n,&m);
    d[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<m);j++){
            if(!d[i-1][j]) continue;
            queue<tp> q;
            q.emplace(0,0);
            while(!q.empty()){
                int y,x;
                tie(y,x) = q.front(); q.pop();
                if(x>=m){
                    d[i][y] += d[i-1][j];
                    d[i][y] %= 9901;
                    continue;
                }
                if(j & (1<<x)) q.emplace(y,x+1); // 이미 채워져 있음
                else{
                    if(x+1<m && !(j&(1<<x+1))) q.emplace(y,x+2); // x,x+1 채움
                    if(i<n) q.emplace(y|(1<<x),x+1);     // x 채움
                }
            }
        }
    }
    printf("%d",d[n][0]);
}
