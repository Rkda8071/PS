#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
priority_queue<tp,vector<tp>,greater<tp> > pq;
int n,sy,ex;
int main(){
    scanf("%d %d %d",&n,&sy,&ex);
    for(int i=1;i<=n;i++){
        int x,y1,y2;
        scanf("%d %d %d",&x,&y1,&y2);
        pq.emplace(x,y1,y2);
    }
}
