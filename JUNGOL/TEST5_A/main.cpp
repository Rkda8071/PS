#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
priority_queue<tp,vector<tp>, greater<tp> > q;
int n,m;
int a[1000][1000],d[1000][1000];
int yyy[4] = {1,-1,0,0}, xxx[4] = {0,0,1,-1};

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    d[1][1] = a[1][1];
    q.emplace(a[1][1],1,1);
    while(!q.empty()){
        int t,y,x;
        tie(t,y,x) = q.top(); q.pop();
        if(y==n && x==m) break;
        for(int i=0;i<4;i++){
            int yy = y+yyy[i], xx = x+xxx[i],tt = max(t,a[yy][xx]);
            if(yy<=0 || yy>n || xx<=0 || xx>m) continue;
            if(!d[yy][xx] || d[yy][xx]>tt){
                d[yy][xx] = tt;
                q.emplace(d[yy][xx],yy,xx);
            }
        }
    }
    printf("%d",d[n][m]);
    return 0;
}
/*

#include<bits/stdc++.h>
using namespace std;
int n,m,cur;
int a[1000][1000],chk[1000][1000];
int yyy[4] = {1,-1,0,0}, xxx[4] = {0,0,1,-1};
int f(int y,int x){
    if(y==n && x==m) return 1;
    for(int i=0;i<4;i++){
        int yy = y+yyy[i], xx = x+xxx[i],tt = max(t,a[yy][xx]);
        if(yy<=0 || yy>n || xx<=0 || xx>m) continue;
        if(!d[yy][xx] || d[yy][xx]>tt){
            d[yy][xx] = tt;
            if(f(yy,xx)) return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            r = max(r,a[i][j]);
        }
    }
    l = a[n][m];
    while(l<r){

    }

}
*/
