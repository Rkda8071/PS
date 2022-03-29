#include<bits/stdc++.h>
using namespace std;
int k,n;
int a[110],b[110];
int d[110],path[110],cnt;
void init(){
    scanf("%d %d",&k,&n);
    for(int i=1;i<=n+1;i++) {
        scanf("%d",&a[i]);
        if(i!=0) a[i] += a[i-1];
    }
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n+1;i++) d[i] = -1;
}
void trace(int x){
    if(x==0){
        printf("%d\n",cnt);
        return;
    }
    ++cnt;
    trace(path[x]);
    printf("%d ",x);
}
int main(){
    init();
    for(int i=1;i<=n+1;i++){
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]>k) break;
            if(d[j]==-1) continue;
            if(d[i] == -1 || d[i]>d[j]+b[i]){
                d[i] = d[j] + b[i];
                path[i] = j;
            }
        }
    }
    if(a[n+1]<=k) printf("0\n0");
    else{
        printf("%d\n",d[n+1]);
        trace(path[n+1]);
    }
    return 0;
}
