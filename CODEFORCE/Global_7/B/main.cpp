#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010],b[200010],maxim;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    maxim = a[1] = b[1];
    for(int i=2;i<=n;i++){
        a[i] = b[i] + maxim;
        maxim = max(a[i],maxim);
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}
