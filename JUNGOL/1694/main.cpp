#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct A{
    double x,y;
};
struct L{
    int a,b,c;
    L() {}
    L(A a1,A a2){
        a = a2.y-a1.y;
        b = a1.x-a2.x;
        c = a1.y*a2.x - a1.x*a2.y;
    }

    bool isparallel(L x){
        return (a*x.b == b*x.a); // ÆòÇà
    }
}l[1010];

bool inside(A p) {
    if (abs(p.x) > 100.0 || abs(p.y) >100.0) return false;
    int x = int(p.x * 1e6), y = int(p.y * 1e6);
    return 1;//(abs(x) <=10000000
}

int xxx[4] = {-10,10,10,-10}, yyy[4] = {10,10,-10,-10};

A fin(L a1,L a2){
    if(a1.isparallel(a2)) return {100,100};
    return {(double)(a1.b*a2.c-a1.c*a2.b)/(double)(a1.a*a2.b-a1.b*a2.a)
            ,(double)(a1.a*a2.c-a1.c*a2.a)/(double)(a1.b*a2.a-a1.a*a2.b)};
}
int chk[1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        l[i] = L({x1,y1},{x2,y2});
        if((x1<-10&&x2<-10) || (10<x1&&10<x2) || (y1<-10&&y2<-10) || (10<y1&&10<y2)) chk[i] = -10;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            A ang = fin(l[i],L({xxx[j],yyy[j]},{xxx[(j+1)%4],yyy[(j+1)%4]}));
            if(-10.0f<=ang.x && ang.x<=10.0f && -10.0f<=ang.y && ang.y<=10.0f)
                chk[i]++;
        }
    }
    int dap = 1;
    for(int i=1;i<=n;i++){
        if(chk[i]<1) continue;
        ++dap;
        for(int j=1;j<i;j++){
            if(chk[j]<1) continue;
            A ang = fin(l[i],l[j]);
            if(-10.0f<ang.x && ang.x<10.0f && -10.0f<ang.y && ang.y<10.0f) dap++;
        }
    }
    printf("%d",dap);
    return 0;
}
