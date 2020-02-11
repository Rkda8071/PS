#include<bits/stdc++.h>
using namespace std;
int a[101],n;
bool f(int x){
    int k = x/2;
    for(int i=1;i<=x/2;i++){
        for(int j=x;j>=x-i;j--){
            if(j == x-i) return false;
            else if(a[j] != a[j-i]) break;
        }
    }
    if(x==n) return true;
    for(int i=1;i<=3;i++){
        a[x+1] = i;
        if(f(x+1)) return true;
        a[x+1] = 0;
    }
    return false;
}
int main(){
    scanf("%d",&n);
    a[1] = 1;
    f(1);
    for(int i=1;i<=n;i++) printf("%d",a[i]);
    return 0;
}
