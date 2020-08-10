#include<bits/stdc++.h>
using namespace std;
int n,k,dap;
int cnt[1010],a[100100];
priority_queue<int> maxim;
priority_queue<int, vector<int>, greater<int> > mini;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<k;i++){
        if(!cnt[a[i]]){
            maxim.push(a[i]);
            mini.push(a[i]);
        }
        cnt[a[i]]++;
    }

    for(int i=k;i<=n;i++){
        if(!cnt[a[i]]){
            maxim.push(a[i]);
            mini.push(a[i]);
        }
        cnt[a[i]]++;

        dap = max(dap,maxim.top() * mini.top());

        cnt[a[i-k+1]]--;
        while(!maxim.empty() && !cnt[maxim.top()]) maxim.pop();
        while(!mini.empty() && !cnt[mini.top()]) mini.pop();
    }
    printf("%d",dap);
    return 0;
}
