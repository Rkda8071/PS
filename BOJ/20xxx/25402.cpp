#include<bits/stdc++.h>
using namespace std;
int n,q,k,s[250010];
vector<int> a[250010];
int main(){
    scanf("%d",&n);
    for(int x,y,i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    scanf("%d",&q);
    while(q--){
        scanf("%d",&k);
        for(int i=0;i<k;i++){

        }
    }
}