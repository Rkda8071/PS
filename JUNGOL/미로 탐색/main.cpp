#include<bits/stdc++.h>
using namespace std;
vector<int> a[100100];
int chk[100100];
int main(){
    int n,m;
    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
