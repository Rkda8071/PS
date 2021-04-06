#include<bits/stdc++.h>
using namespace std;
int n,s;
struct A{
    int h,c;
    bool operator<(const A &r)const{
        return h<r.h || (h==r.h && c>r.c);
    }
    bool operator<(const int &x)const{
        return h<x;
    }
}a[300010];
int d[300010];
void f(int i){
    if(a[i].h<s) return;
    int x = lower_bound(a,a+i,a[i].h-s) - a;
    if(a[x].h != a[i].h-s) x--;
    d[i] = max(d[x] + a[i].c,d[i-1]);
}
int main(){
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].h,&a[i].c);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        f(i);
    printf("%d",d[n]);
    return 0;
}
