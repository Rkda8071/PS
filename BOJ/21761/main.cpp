#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll d[4][200100];
vector<ll> a[4];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<4;i++) scanf("%d",&d[i][0]);
    for(int i=0;i<n;i++){
        char x;
        int y;
        scanf(" %c %d",&x,&y);
        a[x-'A'].push_back(y);
    }
    for(int i=0;i<4;i++)
        sort(a[i].begin(),a[i].end(),greater<int>());


    return 0;
}
