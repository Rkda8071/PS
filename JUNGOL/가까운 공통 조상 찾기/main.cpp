// JUNGOL
/*#include<bits/stdc++.h>
using namespace std;
int a[10010];
vector<int> d1,d2;
void f(int x, vector<int> &d){
    d.push_back(x);
    if(a[x]==0) return;
    else f(a[x],d);
}
int main(){
    int n;
    int x,y;
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        scanf("%d %d",&x,&y);
        a[y] = x;
    }
    scanf("%d %d",&x,&y);
    f(x,d1); f(y,d2);
    n = min(d1.size(),d2.size());
    int dap;
    for(int i=1;i<=n;i++){
        if(d1[d1.size() - i] == d2[d2.size() - i]) dap = d1[d1.size() - i];
        else break;
    }
    printf("%d",dap);
    return 0;
}*/

// BOJ 3584
#include<bits/stdc++.h>
using namespace std;
int a[10010];
int d1[10010],d2[10010],c1,c2;
void f(int x, int d[], int &c){
    d[c++] = x;
    if(a[x]==0) return;
    else f(a[x],d,c);
}
int main(){
    int n,t;
    int x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) a[i] = 0;
        for(int i=1;i<n;i++) {
            scanf("%d %d",&x,&y);
            a[y] = x;
        }
        scanf("%d %d",&x,&y);
        f(x,d1,c1); f(y,d2,c2);
        n = min(c1,c2);
        int dap;
        for(int i=1;i<=n;i++){
            if(d1[c1 - i] == d2[c2 - i]) dap = d1[c1 - i];
            else break;
        }
        printf("%d\n",dap);
    }
    return 0;
}
