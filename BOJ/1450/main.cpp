#include<bits/stdc++.h>
using namespace std;
int n,m,k,dap;
int a[50];
vector<int> arr;

void f(int x,int cur){
    if(x>m){
        arr.push_back(cur);
        return;
    }
    if(cur+a[x]<=k) f(x+1,cur+a[x]);
    f(x+1,cur);
}
void g(int x,int cur){
    if(x>n){
        int idx = upper_bound(arr.begin(),arr.end(),k-cur) - arr.begin();
        idx--;
        dap += idx+1;
        return;
    }
    if(cur+a[x]<=k) g(x+1,cur+a[x]);
    g(x+1,cur);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    m = (n+1) >> 1;
    f(1,0);
    sort(arr.begin(),arr.end());
    g(m+1,0);
    printf("%d",dap);
}
