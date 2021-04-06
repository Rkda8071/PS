#include<bits/stdc++.h>
using namespace std;
int n,t,a[100100],d[100100];
bool f(){
    int x1,x2;
    x1 = x2 = 0;
    for(int i=1;i<=n;i++){
        if(a[i]>d[i]){
            if(!x1) return false;
        } else if(a[i]<d[i]){
            if(!x2) return false;
        }
        if(a[i]==-1) x1 = 1;
        if(a[i]==1) x2 = 1;
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
}
