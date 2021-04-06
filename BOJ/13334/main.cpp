#include<bits/stdc++.h>
using namespace std;
int n,d,maxim;
struct A{
    int s,e;
    bool operator<(const A &r)const{ return e<r.e || (e==r.e && s<r.s);}
} a[100100];
void input(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&a[i].s,&a[i].e);
        if(a[i].s>a[i].e) swap(a[i].s,a[i].e);
    }
    scanf("%d",&d);
    sort(a,a+n);
}
void f(){
    priority_queue<int,vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(a[i].s);
        while(!pq.empty() && pq.top() + d < a[i].e) pq.pop();
        maxim = max(maxim,(int)pq.size());
    }
}
int main(){
    input();
    f();
    printf("%d",maxim);
    return 0;
}
