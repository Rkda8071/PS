#include<bits/stdc++.h>
using namespace std;

int n,a[100100];
void init(){
    scanf("%d",&n);
    a[0] = a[n+1] = 1000000000;
    /*printf("? 1\n");
    fflush(stdout);
    scanf("%d",&a[1]);

    printf("? %d\n",a[1]);
    fflush(stdout);
    scanf("%d",&a[a[1]]);*/
}
int solve(){
    int l=0,r=n+1,mid;
    if(a[l] == 1) return l;
    if(a[r] == 1) return r;
    mid = (l+r)/2;
    printf("? %d\n",mid);
    fflush(stdout);
    scanf("%d",&a[mid]);

    while(l+1<r){
        int m;
        if(mid-l > r-mid) m = (l+mid)/2;
        else m = (r+mid)/2;
        printf("? %d\n",m);
        fflush(stdout);
        scanf("%d",&a[m]);
        if(a[mid] == 1) return mid;
        if(a[m]>a[mid]){
            if(mid-l > r-mid) l = m;
            else r = m;
        }else{
            if(mid-l > r-mid) r = mid;
            else l = mid;
            mid = m;
        }
    }
    return mid;
}
int main(){
    init();
    printf("! %d",solve());
    return 0;
}
