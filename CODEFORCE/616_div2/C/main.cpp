#include<bits/stdc++.h>
using namespace std;
int a[4000];
int main(){
    int t;
    int n,m,k;
    int l,r,maxim;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        k = min(k,m-1); maxim = 0;
        for(int i=0;i<=k;i++){
            l = i+1; r = n-k+i;
            for(int j=k+1;j<m;j++){
                if(a[l]>a[r]) l++;
                else if(a[l]<a[r]) r--;
                else{
                    //sibal
                }
            }
            maxim = max(maxim,max(a[l],a[r]));
        }
        printf("%d\n",maxim);
    }
    return 0;
}
