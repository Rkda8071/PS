#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int k,n;
vector<tp> a[41];
int cur[41];
priority_queue<tp,vector<tp>,greater<tp> > pq;
bool f(int x){
    int e,c;
    /*for(int i=0;i<a[x].size();i++){
        tie(s,c) = a[x][i];
        if(cur[x]-cur[s-1] != c) return false;
    }*/
    for(int i=1;i<=x;i++){
        for(int j=a[i].size()-1;j>=0;j--){
            tie(e,c) = a[i][j];
            if(e<x) break;
            if(cur[x] - cur[i-1]>c || e-x+(cur[x]-cur[i-1])<c) return false;
        }
    }
    if(x==k){
        for(int i=1;i<=k;i++){
            if(cur[i]!=cur[i-1]) printf("#");
            else printf("-");
        }
        return true;
    }
    cur[x+1] = cur[x]+1;
    if(f(x+1)) return true;
    cur[x+1] = cur[x];
    if(f(x+1)) return true;
    return false;
}
void init(){
    int x,y,z;
    scanf("%d %d",&k,&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(tp(y,z));
    }
    for(int i=1;i<=k;i++) sort(a[i].begin(),a[i].end());
}
int main(){
    init();
    if(!f(0)) printf("NONE");
    return 0;
}
