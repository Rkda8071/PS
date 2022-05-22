#include<bits/stdc++.h>
using namespace std;
int t,tt,n,k;
int a[1000][1000],cnt;
pair<int,int> ans[100000];
int yyy[4] = {0,0,1,-1}, xxx[4] = {1,-1,0,0};
typedef tuple<int,int,int> tp;
void init(){
    scanf("%d %d",&n,&k);
    int ang = 0,nn=n,x=0,y=1,sw=1;
    while(nn>0){
        for(int i=0;i<nn;i++){
            x += sw;
            a[y][x] = ++ang;
        }
        nn--;
        for(int i=0;i<nn;i++){
            y += sw;
            a[y][x] = ++ang;
        }
        sw *= -1;
    }
}
bool dfs(int y,int x,int z){
    if(z == k){
        if(y == n && x == n){
            return true;
        }
        return false;
    }
    for(int i=0;i<4;i++){
        int yy = y+yyy[i], xx = x+xxx[i];
        if(a[yy][xx] > a[y][x]){

            if(a[yy][xx] > a[y][x]+1) ans[cnt++] = make_pair(a[y][x], a[yy][xx]);
            if(dfs(yy,xx,z+1)) return true;
            if(a[yy][xx] > a[y][x]+1) cnt--;
        }
    }
    return false;
}
void solve(){
    int ang = 0,nn=n,x=0,y=1,sw=1;
    n = n/2+1;
    while(nn>0){
        for(int i=0;i<nn;i++){
            x += sw;
            if(k == abs(n-y) + abs(n-x)){
                dfs(y,x,0);
                return;
            }
            --k;
        }
        nn--;
        for(int i=0;i<nn;i++){
            y += sw;
            if(k == abs(n-y) + abs(n-x)){
                dfs(y,x,0);
                return;
            }
            --k;
        }
        sw *= -1;
    }
}

int main(){
    scanf("%d",&t);
    for(tt=1; tt<=t; tt++){
        printf("Case #%d: ",tt);
        init();
        cnt = 0;
        solve();
        if(cnt>0){
            printf("%d\n",cnt);
            for(int i=0;i<cnt;i++)
                printf("%d %d\n",ans[i].first,ans[i].second);
        }else{
            printf("IMPOSSIBLE\n");
        }
    }
}
