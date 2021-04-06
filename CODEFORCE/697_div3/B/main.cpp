#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int cnt = n/2020;
        n = n%2020;
        if(cnt>=n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
