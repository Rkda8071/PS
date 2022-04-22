#include<bits/stdc++.h>
using namespace std;
int n;
int len[1001];
//char a[21][1001];

struct A{
    //int idx,last;
    string s;
    bool operator < (const A &r)const{
        return s + r.s > r.s + s;
    }
}a[21];

priority_queue<A> pq;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //scanf(" %s",a[i]);
        cin >> a[i].s;
        pq.push(a[i]);
    }
    int cex = 0;
    while(!pq.empty()){
        A ang = pq.top(); pq.pop();
        printf("%c",ang.s[0]);
        ang.s.erase(ang.s.begin());
        if(ang.s.begin() != ang.s.end()) pq.push(ang);
    }
    
    return 0;
}