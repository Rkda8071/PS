#include<bits/stdc++.h>
using namespace std;
int n,a[1000100];
bool f(int x){
    if(x>0 && a[x] == a[x-1]) return false;
    if(x==n) return true;
    if(!a[x]){
        for(int i=1;i<=3;i++){
            if(a[x-1] == i) continue;
            a[x] = i;
            if(f(x+1)) return true;
        }
    }else return f(x+1);
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    if(f(0)){
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
    }else printf("-1");
}
