#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int n,m,idx[300010];
vector<int> v[300010],ans;
priority_queue<p> pq,s;
void init(){
    scanf("%d",&n);
    for(int x,i=1;i<=n;i++){
        scanf("%d",&x);
        v[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(v[i].size()){
            pq.push(p(-v[i][0],i));
            s.push(p(v[i].size(), i));
        }
    }
    m = n;
}

bool solve(){
    int prev = 0,ang=0;
    while(!pq.empty()){
        if(s.top().first > m/2){
            ang = s.top().second;
            if(s.top().first > m/2 + 1 || m%2==0)
                return false;
            break;
        }
        int y,x;
        y = -pq.top().first;
        x = pq.top().second; pq.pop();
        if(idx[prev] != v[prev].size()){
            pq.push(p(-v[prev][idx[prev]],prev));
        }

        ans.push_back(y);
        idx[x]++;
        --m;
        prev = x;

        while(!s.empty()){
            int yy,xx;
            yy = s.top().first;
            xx = s.top().second;

            if(v[xx].size() - idx[xx] != yy){
                s.pop();
                if(v[xx].size() != idx[xx]) s.push(p((int)v[xx].size() - idx[xx],xx));
            }
            else break;
        }
        
    }
    while(m>1){
        if(!pq.empty() && ang == pq.top().second){
            pq.pop();
            continue;
        }
        --m;
        ans.push_back(v[ang][idx[ang]++]);
        if(idx[prev] != v[prev].size()){
            pq.push(p(-v[prev][idx[prev]],prev));
        }
        
        int y,x;
        y = -pq.top().first;
        x = pq.top().second; pq.pop();
        ans.push_back(y);
        idx[x]++;
        --m;
        prev = x;
    }
    ans.push_back(v[ang][idx[ang]++]);
    return true;
}
int main(){
    init();
    if(solve()){
        for(int x : ans)
            printf("%d ",x);
    }else{
        printf("-1");
    }
}