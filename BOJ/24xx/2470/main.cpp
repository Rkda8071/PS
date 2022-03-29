#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n,dapl=1,dapr=n;
    while(l<r){
        int m = a[l]+a[r];
        if(abs(m)<abs(a[dapl]+a[dapr])){
            dapl = l;
            dapr = r;
        }
        if(m<0)
            l++;
        else
            r--;
    }
    printf("%d %d",a[dapl],a[dapr]);
    return 0;
}
