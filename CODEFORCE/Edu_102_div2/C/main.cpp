#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int p[200100];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        int ang = k;
        for(int i=1;i<=k;i++) p[i] = i;
        for(int i=k-(n-k);i<=k;i++) p[i] = ang--;
        for(int i=1;i<=k;i++) printf("%d ",p[i]);
        puts("");
    }
    return 0;
}
