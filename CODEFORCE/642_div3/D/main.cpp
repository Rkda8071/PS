#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
int a[200010];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        priority_queue<tp,vector<tp>,greater<tp> > q;
        int l,r,m,id=0;

        q.emplace(n-n,1,n);
        while(!q.empty()){
            tie(m,l,r) = q.top(); q.pop();
            if(l>r) continue;
            if((r-l+1)%2){
                m = (l+r)/2;
                a[m] = ++id;
            } else{
                m = (l+r-1)/2;
                a[m] = ++id;
            }
            q.emplace(n-(m-l),l,m-1);
            q.emplace(n-(r-m),m+1,r);
        }
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}
