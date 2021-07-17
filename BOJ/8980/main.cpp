#include<bits/stdc++.h>
using namespace std;
int n,c,m,d[2010];
typedef tuple<int,int> tp;
vector<tp> a[2010];

int main(){
    scanf("%d %d %d",&n,&c,&m); //마을, 용량, 화물
    while(m--){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(tp(y,z));
    }

    int cur = 0,dap = 0;
    for(int i=1;i<=n;i++){
        dap += d[i];
        cur -= d[i];
        for(auto x=a[i].begin();x!=a[i].end();x++){
            int y,z;
            tie(y,z) = *x;
            d[y] += z;
            cur += z;
        }
        for(int j=n;j>i;j--){
            if(cur<=c) break;
            if(cur-d[j]>c){
                cur -= d[j];
                d[j] = 0;
            }else{
                d[j] -= cur-c;
                cur = c;
            }
        }
    }
    printf("%d",dap);
    return 0;
}
