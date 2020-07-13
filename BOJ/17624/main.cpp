#include<bits/stdc++.h>
using namespace std;
int n,b,chk[5010];
vector<int> a[5010];
void init(){
    int x,y;
    scanf("%d %d",&n,&b);
    for(int i=1;i<=b;i++){
        scanf("%d",&x);
        chk[x] = 1;
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
int main(){
    init();
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y); // x개의 정점을 가지고 y개의 검은 돌이 놓여있는 서브트리 존재?

    }
}
