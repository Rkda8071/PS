#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int,int,int> tp;

int n,m;
char a[110][110];
int xxx[6] = {-1,-1,0,0,1,1},yyy[6] = {1,0,1,0,1,0};
bool f(){
    queue<tp> q;
    int chk[110][110][6] = {0}, chk1[110][110][6] = {0};
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf(" %s",a[i]+1);
    int sy,sx;
    for(int i=1;i<=m;i++){
        if(a[n][i]=='*'){
            sy = n; sx = i; break;
        }
    }
    q.emplace(0,sy,sx,sy,sx); // 0이면 손이 나갈 차례 , (손), (발)
    while(!q.empty()){
        int t,hy,hx,fy,fx;
        tie(t,hy,hx,fy,fx) = q.front(); q.pop();
        if(!t){ // 손을 움직일 때
            for(int i=0;i<6;i++){
                int yy = fy - yyy[i], xx = fx + xxx[i];
                if((a[yy][xx] == 'B' || a[yy][xx] == 'H') && !chk[fy][fx][i]){
                    chk[fy][fx][i] = 1;
                    q.emplace(1,yy,xx,fy,fx);
                }
            }
        }else{ // 발을 움직일 때
            for(int i=0;i<6;i++){
                int yy = hy + yyy[i], xx = hx + xxx[i];
                if((a[yy][xx] == 'B' || a[yy][xx] == 'F') && !chk1[hy][hx][i]){
                    chk1[hy][hx][i] = 1;
                    q.emplace(0,hy,hx,yy,xx);
                    if(yy == 1) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        if(f()) printf("Climbable\n");
        else printf("Not Climbable\n");
    }
    return 0;

}
