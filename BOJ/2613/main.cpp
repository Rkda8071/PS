#include<bits/stdc++.h>
using namespace std;
int a[310];
int n,m;
bool f(int maxim){
    int hap = 0,cnt = 1;
    for(int i=1;i<=n;i++){
        hap += a[i];
        if(hap>maxim){
            ++cnt;
            hap = a[i];
        }
    }
    if(cnt<=m) return true;
    else return false;
}
int main(){
    scanf("%d %d",&n,&m);
    int l=1,r=0,mid;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        l = max(l,a[i]);
        r += a[i];
    }
    while(1){
        if(l>=r) break;
        mid = (l+r)/2;
        if(f(mid)){
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    if(f(l)) printf("%d\n",l);
    else printf("%d\n",++l);
    int hap = 0,cnt = 0;
    for(int i=1;i<=n;i++){
        hap += a[i];
        ++cnt;
        if(hap+a[i+1]>l || n-i+1 == m){
            printf("%d ",cnt);
            m--;
            cnt = 0;
            hap = 0;//a[i];
        }

    }
    if(cnt>0) printf("%d",cnt);
    return 0;
}
