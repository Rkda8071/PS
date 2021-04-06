#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int hap = a+b+c;
        if(hap%9 || (hap/9)>min(a,min(b,c)) ) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
