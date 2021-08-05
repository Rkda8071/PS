#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,k,d[20][100100],p[100100];
vector<tp> a[100100];
bool chk[100100];

void dfs(int x,int lev){
    chk[x] = true;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(tp(y,z));
        a[y].push_back(tp(x,z));
    }
    dfs(1,0);
}
