#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
tp a[1000010];
vector<tp> d;
int x,y,xx,yy,s,e,n,m;
void solve(){
    a[n+1] = a[1];
    tie(x,y) = a[1];
    s = -2000000000;
    for(int i=1;i<=n;i++){
        tie(xx,yy) = a[i+1];
        if(s==-2000000000 && y<=0 && yy>0) s = x;
        if(y>0 && yy<=0){
            d.push_back(tp(min(s,x),max(s,x)));
            s = -2000000000;
        }
        x = xx; y = yy;
    }
    if(get<0>(d[0]) == -2000000000) d[0] = tp(min(s,get<1>(d[0])),max(s,get<1>(d[0])));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        a[i] = tp(x,y);
    }

    solve();

    int dap1=0,dap2=0;
    sort(d.begin(),d.end());
    m = -2000000000;
    for(int i=0;i<d.size();i++){
        tie(s,e) = d[i];
        if(m<s){
            dap1++;
            m=e;
        }
    }

    for(int i=0;i<d.size()-1;i++){
        x = get<1>(d[i]);   //지금 있는놈 끝
        xx= get<0>(d[i+1]); //앞에 있는놈 시작
        if(x<xx) ++dap2;
    }
    printf("%d %d",dap1,dap2+1);
    return 0;
}
