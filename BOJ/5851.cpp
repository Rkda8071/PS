#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],b[100010],ans,l;
set<int> s;
map<int, int> idx;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    for(int i=0;i<n;i++){
        if(idx.find(a[i]) == idx.end())
            idx[a[i]] = idx.size();
        s.insert(a[i]);
        ans = max(ans, ++b[idx[a[i]]]);
        while(s.size() > k+1){
            if(--b[idx[a[l]]] == 0)
                s.erase(a[l]);
            l++;
        }
    }
    printf("%d",ans);
}