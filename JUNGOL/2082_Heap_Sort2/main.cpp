#include<bits/stdc++.h>
using namespace std;
int a[2000000];
stack<int> s;
int n,k;
void f(){
    int x = 1;
    while(x*2<=n){
        if(a[x*2+1]<a[x*2]) x = x*2;
        else x = x*2+1;
        a[x/2] = a[x];
    }
    a[x] = 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        k = i;
        while(k>1){
            if(a[k]>a[k/2]) swap(a[k],a[k/2]);
            else break;
            k/=2;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    puts("");
    for(int i=1;i<=n;i++){
        s.push(a[1]);
        f();
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}
