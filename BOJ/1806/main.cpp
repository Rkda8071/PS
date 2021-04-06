#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,s;
bool f(int m){
    for(int i=m;i<=n;i++)
        if(a[i]-a[i-m]>=s) return true;
    return false;
}
int main(){
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    int l=1,r=n,mid;
    if(!f(n)){
        printf("0");
        return 0;
    }
    while(1){
        if(r<=l) break;
        mid = (l+r)/2; //2,3 -> mid = 2
        if(f(mid)) r = mid-1;
        else l = mid+1;
    }
    if(f(l)) printf("%d",l);
    else printf("%d",l+1);
    return 0;
}
