#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n,hap=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        hap += (n-i+1)*a[i];
    printf("%d",hap);
    return 0;
}
