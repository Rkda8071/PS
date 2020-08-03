#include<bits/stdc++.h>
using namespace std;

int a[200];
int n,k,maxim;
int chk[2000000];
set<int> s[151][151];

ll solve(){
    if(maxim<k) return k;
    else if(maxim==k) return k+1;
    for(int k=0;k<n;k++){
        for(int s=1;s<=n-k;s++){

        }
    }

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&k);
    for(int i=1;i<=n;i++) maxim += a[n-i+1]*i;
    solve();
}
