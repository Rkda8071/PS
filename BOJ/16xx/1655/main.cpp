#include<bits/stdc++.h>
using namespace std;
priority_queue<int> l;
priority_queue<int, vector<int>, greater<int> > r;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        r.emplace(x);
        if(l.size() < r.size()){
            l.emplace(r.top());
            r.pop();
        }else if(!l.empty() && !r.empty()){
            if(l.top()>r.top()){
                r.emplace(l.top()); l.pop();
                l.emplace(r.top()); r.pop();
            }
        }
        printf("%d\n",l.top());
    }
    return 0;
}
