#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nn,n,m;
ll seg[401000];
void init(){
    scanf("%d",&n);
    for(nn=1;nn<n;nn*=2);
    for(int i=nn;i<nn+n;i++) scanf("%d",&seg[i]);
    for(int i=nn-1;i>=1;i--) seg[i] = seg[i*2] + seg[i*2];

}
int main(){
    init();
}
