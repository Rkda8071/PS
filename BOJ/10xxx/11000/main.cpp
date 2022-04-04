#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
priority_queue<int,vector<int>,greater<int> > pq;
p a[200100];
int n,maxim;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[i] = make_pair(x,y);
    }
    sort(a,a+n);

    for(int i=0;i<n;i++){
        int s,e,ang;
        tie(s,e) = a[i];
        while(!pq.empty() && pq.top()<=s) pq.pop();
        pq.push(e);

        ang = pq.size();
        maxim = max(maxim,ang);
    }
    printf("%d",maxim);
    return 0;
}
