#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
}a[10010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[i] = {x,y};
    }
    return 0;
}
