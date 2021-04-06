#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[200010],l[200010],r[200010];
queue<int> q;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) l[i]=r[i]=0;
        for(int i=1;i<=n;i++) r[a[i]]++;
        for(int i=1;i<n;i++){
            l[a[i]]++;
            r[a[i]]--;
            cnt = 0;
            for(int j=1;j<=n && l[j]==1;j++)
                cnt += l[j];
            if(cnt!=i) continue;
            cnt = 0;
            for(int j=1;j<=n && r[j]==1;j++)
                cnt += r[j];
            if(cnt!=n-i) continue;
            q.push(i); q.push(n-i);
        }
        printf("%d\n",q.size()/2);
        while(!q.empty()){
            printf("%d ",q.front()); q.pop();
            printf("%d\n",q.front()); q.pop();
        }
    }
    return 0;
}
