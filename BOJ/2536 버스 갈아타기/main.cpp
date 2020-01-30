#include<bits/stdc++.h>
using namespace std;
struct A{
    int sx,sy,ex,ey,lev;
    bool isCross(A &r){
        return !(sx>r.ex || r.sx>ex || r.sy>ey || sy>r.ey);
    }
}a[5010];
int k,fr,re = 1;
int bfs(){
    while(fr<re){
        for(int i = re;i<=k;++i){
            if(a[fr].isCross(a[i])){
                if(i==k) return a[fr].lev;
                a[i].lev = a[fr].lev+1;
                swap(a[re++],a[i]);
            }
        }
        fr++;
    }
    return -1;
}
int main(){
    int n,m;
    int sx,sy,ex,ey;
    scanf("%d %d %d",&m,&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%*d %d %d %d %d",&sx,&sy,&ex,&ey);
        if(sx>ex || sx==ex && sy>ey){
            swap(sx,ex);
            swap(sy,ey);
        }
        a[i] = {sx,sy,ex,ey,0};
    }
    scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
    a[0] = {sx,sy,sx,sy,0};
    a[++k] = {ex,ey,ex,ey,0};
    printf("%d",bfs());
    return 0;
}
