#include<bits/stdc++.h>
using namespace std;
int n;
int a[60][60],d[60],chk[27],mini = 2000000000,dap;
priority_queue<tuple<int,int> > pq;
void in(){
    char x,y;
    int xx,yy,z;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c %c %d",&x,&y,&z);
        if('A'<= x && x <='Z'){
            xx = x-'A';
            chk[xx] = 1;
        } else xx = x-'a'+26;

        if('A'<= y && y <='Z'){
            yy = y-'A';
            chk[y] = 1;
        } else yy = y-'a'+26;

        if(a[xx][yy]==0 || a[xx][yy]>z) a[xx][yy] = z;
        if(a[yy][xx]==0 || a[yy][xx]>z) a[yy][xx] = z;
    }
}
void f(){
    int x,y;
    pq.emplace(0,'Z'-'A');
    for(int i=0;i<52;i++) d[i] = 2000000000;
    chk['Z'-'A'] = 0;
    d['Z'-'A'] = 0;
    while(!pq.empty()){
        tie(x,y) = pq.top(); pq.pop();
        if(d[y]!=x) continue;
        if(y<26 && chk[y]){
            if(mini>x){
                dap = y;
                mini = x;
            }
            continue;
        }
        for(int i=0;i<52;i++){
            if(a[y][i]!=0 && d[i]>d[y]+a[y][i]){
                d[i] = d[y]+a[y][i];
                pq.emplace(d[i],i);
            }
        }
    }
}
int main(){
    in();
    f();
    printf("%c %d",dap+'A',mini);
    return 0;
}
