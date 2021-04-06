#include<bits/stdc++.h>
using namespace std;
int n,t;
char a[110];
bool f(){
    for(int i=n;i>=1;i--){
        if(a[i]!=')') return i<n-i;
    }
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",a+1);
        if(f()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
