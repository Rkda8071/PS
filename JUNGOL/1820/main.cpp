#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
} a[1010];
int n,m;
int dis(int x,int y){ return abs(a[x].x - a[y].x) + abs(a[x].y - a[y].y); }
int d[1010][1010],path[1010][1010];
void init(){
    int y,x;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d %d",&a[i].y,&a[i].x);
    d[1][0] = a[1].y + a[1].x - 2;
    d[0][1] = 2*n - a[1].y - a[1].x;
    for(int i=2;i<=m;i++){
        d[i][0] = d[i-1][0] + dis(i,i-1);
        d[0][i] = d[0][i-1] + dis(i,i-1);
    }
}

int main(){
    init();
    for(int i=1;i<=n;i++){
        d[i+1][i] = a[i+1].x + a[i+1].y - 2 + d[0][i];
        d[i][i+1] = 2*n - a[i+1].y - a[i+1].x + d[i][0];
        for(int j=1;j<i;j++) {
            d[i+1][i] = min(d[i+1][i],d[j][i] + dis(j,i+1));
            d[i][i+1] = min(d[i][i+1],d[i][j] + dis(j,i+1));
        }
        for(int j=i+2;j<=m;j++){
            d[j][i] = d[j-1][i]+dis(j,j-1);
            d[i][j] = d[i][j-1]+dis(j,j-1);
        }
    }

    int mini = 2000000000;
    int x,y;
    for(int i=0;i<m;i++){
        if(mini>d[i][m]){
            y = i; x = m;
            mini = d[y][x];
        } if(mini>d[m][i]){
            y = m; x = i;
            mini = d[y][x];
        }
    }
    printf("%d\n",d[y][x]);
    stack<int> s;
    while(y || x){
        if(y>x){
            a[0] = {1,1};
            s.push(1);
            while(--y>x) {
                s.push(1);
                //--y;
            }
            for(int i=x-1;i>=0;i--){
                if(d[y+1][x] == d[i][x] + dis(i,y+1)){
                    y = i;
                    break;
                }
            }
        } else{
            a[0] = {n,n};
            s.push(2);
            while(--x>y) {
                s.push(2);
            }
            for(int i=y-1;i>=0;i--){
                if(d[y][x+1] == d[y][i] + dis(i,x+1)){
                    x = i;
                    break;
                }
            }
        }
    }
    while(!s.empty()){
        printf("%d\n",s.top());
        s.pop();
    }
    return 0;
}
