#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
priority_queue<tp,vector<tp>,greater<tp> > pq;
char chk[4] = {'<', '>', '^', 'v'};
char a[700][700];
int yyy[4] = {0,0,-1,1}, xxx[4] = {-1,1,0,0};
int d[700][700];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf(" %s",&a[i][1]);
    pq.emplace(0,1,1);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j] = 2000000000;
    d[1][1] = 0;
    while(!pq.empty()){
        int t,y,x;
        tie(t,y,x) = pq.top(); pq.pop();
        for(int i=0;i<4;i++){
            int yy = y+yyy[i], xx = x+xxx[i], tt = t+((chk[i] == a[y][x]) ? 0 : 1);
            if(yy>=1 && yy<=n && xx>=1 && xx<=m && d[yy][xx] > tt){
                d[yy][xx] = tt;
                pq.emplace(tt,yy,xx);
            }
        }
    }
    printf("%d",d[n][m]);
    return 0;
}
