#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a[510];
int s[510][510],l[510][510],c[510];
void f(int x){
    s[x][x] = 1; c[x]++;
    for(int i=a[x].size();i>=0;i--){

    }
    for(int i=1;i<=n;i++){
        for(int j=a[x].size()-1;j>=0;j--){
            if(l[a[x][j]][i]){

            }
        }
    }
    for(int i=1;i<=n;i++){
        if(s[x][i]){
            for(int j=a[x].size()-1;j>=0;j--){
                if(s[a[x][j]][i]==0){
                    c[a[x][j]]++;
                    s[a[x][j]][i] = 1;
                }
            }
        }
    }
}
int main(){
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(chk[i] == 0) f(i);
    }
}
