#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,t,chk[200100];
char a[200100];
int main(){
    scanf("%d",&t);
    while(t--){
        int dap = 0;
        scanf("%d",&n);
        scanf("%s",a+1);
        priority_queue<int,vector<int>,greater<int> > pq0,pq1;
        for(int i=1;i<=n;i++){
            if(a[i] == '0'){
                if(pq1.empty())
                    pq0.emplace(chk[i] = ++dap);
                else{
                    chk[i] = pq1.top();
                    pq0.emplace(chk[i]);
                    //chk[i] = pq1.top();
                    pq1.pop();
                }
            }else{
                if(pq0.empty())
                    pq1.emplace(chk[i] = ++dap);
                else{
                    chk[i] = pq0.top();
                    pq1.emplace(chk[i]);
                    //chk[i] = pq1.top();
                    pq0.pop();
                }
            }
        }
        printf("%d\n",dap);
        for(int i=1;i<=n;i++) printf("%d ",chk[i]);
        puts("");
    }
    return 0;
}
