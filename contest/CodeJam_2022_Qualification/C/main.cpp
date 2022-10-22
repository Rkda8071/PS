#include<bits/stdc++.h>
using namespace std;
int n,a[1000010];
int main(){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int cur=0;
        for(int i=0;i<n;i++){
            if(a[i]>=cur+1) cur++;
        }
        printf("Case #%d: %d\n",tt,cur);
    }
    return 0;
}
