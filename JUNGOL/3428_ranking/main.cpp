#include<bits/stdc++.h>
using namespace std;
int n,m,t;
vector<int> a[100100],b[100100];
int small[100100],large[100100],l,r;
void fs(int x){
    for(int i=a[x].size()-1;i>=0;i--){
        if(!small[a[x][i]]){
            r--; small[a[x][i]] = 1;
            fs(a[x][i]);
        }
    }
}
void fl(int x){
    for(int i=b[x].size()-1;i>=0;i--){
        if(!large[b[x][i]]){
            l++; large[b[x][i]] = 1;
            fl(b[x][i]);
        }
    }
}
int main(){
    int x,y;
    scanf("%d %d %d",&n,&m,&t);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y); // x > y
        b[y].push_back(x); // y < x
    }
    l = 1; r = n;
    for(int i=a[t].size()-1; i>=0; i--){ // t보다 작은 놈들
        if(!small[a[t][i]]){
            small[a[t][i]] = 1; r--;
            fs(a[t][i]);
        }
    }
    for(int i=b[t].size()-1; i>=0; i--){
        if(!large[b[t][i]]){
            large[b[t][i]] = 1; l++;
            fl(b[t][i]);
        }
    }
    printf("%d %d",l,r);
    return 0;
}
