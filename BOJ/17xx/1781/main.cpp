#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> tp;
int n,dap;
priority_queue<tp> in;
priority_queue<int> pq;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        in.emplace(x,y);
    }
    for(int i=n;i>=1;i--){
        while(!in.empty() && in.top().first >= i){
            pq.push(in.top().second);
            in.pop();
        }
        if(!pq.empty())
            dap+=pq.top(),pq.pop();

    }
    printf("%d",dap);
    return 0;
}
