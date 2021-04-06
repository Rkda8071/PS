#include<bits/stdc++.h>
using namespace std;
int n,q,p[200010],d[200010];

struct A{
    int x,a,b;
}a[400010];
int fin(int x){
    if(d[x] == x) return x;
    return d[x] = fin(d[x]);
}
void uni(int x){
    int y = fin(p[x]);
    d[x] = y;
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=2;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) d[i] = i;
    int x,y;
    for(int i=1;i<n+q;i++){
        scanf("%d",&x);
        if(x){
            scanf("%d %d",&x,&y);
            a[i] = {1,x,y};
        }else{
            scanf("%d",&y);
            a[i] = {0,y,0};
        }
    }

    stack<int> s;
    for(int i=n+q-1;i>=1;i--){
        if(a[i].x){
            x = fin(a[i].a); y = fin(a[i].b);
            if(x==y) s.push(1);
            else s.push(0);
        }else uni(a[i].a);
    }
    while(!s.empty()){
        if(s.top()) printf("YES\n");
        else printf("NO\n");
        s.pop();
    }
    return 0;
}
