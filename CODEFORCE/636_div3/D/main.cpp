#include<bits/stdc++.h>
using namespace std;
int t;
int a[200100];
int main(){
    scanf("%d",&t);
    int n,k;
    while(t--){
        priority_queue<int,vector<int>,greater<int> > pq,mini,maxim;
        vector<int> seq;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n/2;i++){
            pq.push(a[i] + a[n-i+1]);
            mini.push(min(a[i],a[n-i+1])+1);
            maxim.push(max(a[i],a[n-i+1])+k);
            seq.push_back(a[i]+a[n-i+1]);
            seq.push_back(min(a[i],a[n-i+1])+1);
            seq.push_back(max(a[i],a[n-i+1])+k);
        }
        int dap = 200000000,hap;
        sort(seq.begin(),seq.end());
        seq.erase(unique(seq.begin(),seq.end()),seq.end());
        for(int i=0;i<seq.size();i++){
            hap = n/2;
            int m = seq[i];
            while(!pq.empty() && pq.top() == m){
                pq.pop();
                --hap;
            }
            while(!mini.empty() && mini.top()<=m) mini.pop();
            while(!maxim.empty() && maxim.top()<m) maxim.pop();
            hap += mini.size() + (n/2) - maxim.size();
            dap = min(hap,dap);
        }
        printf("%d\n",dap);
    }
    return 0;
}
