#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int a[1000010],chk[1000010],p[1000010];
int n,m;
int main(){
    int t=4,x,y,dap;
    //scanf("%d",&t);
    ++t;
    while(--t){
        scanf("%d %d",&n,&m);
        priority_queue<tp,vector<tp>,greater<tp> > pq;
        map<int,int> c;
        stack<int> s;
        for(int i=1;i<=m;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++){
            chk[i] = 0;

            if(a[i]){
                chk[i] = c[a[i]];
                c[a[i]] = i;
            }
        }
        dap = 1;
        for(int i=m;i>=1;i--){
            if(!a[i]){
                if(pq.empty()) s.push(0);
                else{
                    tie(y,x) = pq.top(); pq.pop();
                    s.push(x); p[x] = 0;
                }
            }else{
                if(p[a[i]] == t){
                    dap = 0;
                    break;
                }
                p[a[i]] = t;
                pq.emplace(2000000000-chk[i],a[i]);
            }
        }
        if(!pq.empty()) dap=0;
        if(dap){
            printf("YES\n");
            while(!s.empty()){
                printf("%d ",s.top()); s.pop();
            }
            puts("");
        }else printf("NO\n");
    }
    return 0;
}
