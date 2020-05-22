#include<bits/stdc++.h>
using namespace std;
int p[200010],c[200010],cnt[200010];
vector<int> a[200010];
queue<int> q;
int main(){
    int n,q,b,c,d;
    scanf("%d %d",&n,&q);
    for(int i=2;i<=n;i++){
        scanf("%d",&p[i]);
        cnt[p[i]]++;
    }
    for(int i=1;i<=n;i++) if(!cnt[i]) q.push(i);
    while(!q.empty()){

    }

    for(int i=1;i<=q;i++){
        scanf("%d %d %d",&b,&c,&d);
        if(d){// b랑 c가 연결되어있냐?

        }else{

        }
    }
}
