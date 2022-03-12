#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int> tp;
int n,a[1000100],r,t;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&t);
    while(t--){
        deque<tp> dq;
        scanf("%d",&r);
        dq.push_back(tp(1,0));
        for(int i=2,x,y,z;i<=n;i++){
            if(get<0>(dq.front()) < i - r) dq.pop_front();
            tie(x,y) = dq.front();
            z = y + ((a[x]<=a[i]) ? 1 : 0);
            while(!dq.empty()){
                tie(x,y) = dq.back();
                if(y > z) dq.pop_back();
                else if(y == z && a[x]<=a[i]) dq.pop_back();
                else break;
            }

            dq.push_back(tp(i,z));
        }
        printf("%d\n",get<1>(dq.back()));
    }
    return 0;
}
