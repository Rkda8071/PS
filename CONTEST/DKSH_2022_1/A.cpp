#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,k;
    scanf("%d %d %d %d",&n,&m,&a,&k);
    a -= k;
    printf("%d %d",min(n-1,a) + 1, a/m + ((a%m) ? 1 : 0) + 1);
}