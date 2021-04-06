#include<bits/stdc++.h>
using namespace std;
int a[51],t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        set<int> s;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                s.insert(abs(a[i]-a[j]));
        printf("%d\n",s.size());
    }
    return 0;
}
