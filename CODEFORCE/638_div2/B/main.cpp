#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int a[110],chk[110],cnt,dap[1010];
int main(){
    scanf("%d",&t);
    ++t;
    while(--t){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        cnt = 0;
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(chk[a[i]]!=t) v.push_back(a[i]);
            chk[a[i]] = t;
        }
        if(v.size()>k){
            printf("-1\n");
        }else{
            for(int i=1;i<=100;i++){
                if(v.size()==k) break;
                if(chk[i]!=t){
                    v.push_back(i);
                    chk[i] = t;
                }
            }
            printf("%d\n",v.size()*n);
            for(int i=1;i<=n;i++){
                for(int j=0;j<v.size();j++){
                    printf("%d ",v[j]);
                }
            }
            puts("");
        }
    }
    return 0;
}
