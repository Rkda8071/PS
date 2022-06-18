#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int n,m;
int yy[100001],xx[100001];
bool solve(){
    for(int i=1;i<=100000;i++)
        if(yy[i]%2 || xx[i]%2) return false;
    return true;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int y,x,i=0;i<n+m;i++){
        scanf("%d %d",&y,&x);
        yy[y]++; xx[x]++;
    }
    if(solve()) printf("YES");
    else printf("NO");
    return 0;
}