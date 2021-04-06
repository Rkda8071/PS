#include<bits/stdc++.h>
using namespace std;
int c[200100];
multiset<int> s;
vector<int> dap[200100];
int main(){
    int n,k,cnt=0,x;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        s.insert(x);
    }
    for(int i=k;i>=1;i--) scanf("%d",&c[i]);
    int chk = 1;
    ++cnt;

    while(!s.empty()){
        x = lower_bound(c+1,c+k+1,chk) - c;
        if(k-x+1>=*s.lower_bound(k-x+1)){
            printf("[%d]\n",*s.lower_bound(k-x+1));
            dap[cnt].push_back(*s.lower_bound(k-x+1));
        }
        else{
            cnt++; chk = 1;
            continue;
        }
        s.erase(s.lower_bound(k-x+1));
        ++chk;
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++){
        printf("%d ",dap[i].size());
        for(int j=dap[i].size()-1;j>=0;j--) printf("%d ",dap[i][j]);
        puts("");
    }
    return 0;
}
