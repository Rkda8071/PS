#include<bits/stdc++.h>
using namespace std;
int n;
int l[2010],r[2010],d[2010];
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&l[i]);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    for(int i=1;i<=n;i++) d[i] = -1;
}
int main(){
    init();
    for(int i=1;i<=n;i++){ // l
        for(int j=1;j<=n;j++){ // r
            if(d[j-1]==-1) continue;;
            if(l[i]>r[j])
                d[j] = max(d[j],d[j-1]+r[j]);
        }
        for(int j=n;j>=1;j--){
            if(d[j-1]==-1) continue;
            if(l[i]<=r[j]) d[j] = max(d[j],d[j-1]);
        }
    }
    for(int i=1;i<n;i++) d[n] = max(d[i],d[n]);
    printf("%d",d[n]);
    return 0;
}
