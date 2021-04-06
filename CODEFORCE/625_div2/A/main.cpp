#include<bits/stdc++.h>
using namespace std;
int n;
int a[101],b[101];
int cnta,cntb;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        if(a[i] && b[i]){
            continue;
        }else if(a[i]){
            cnta++;
        }else if(b[i]){
            cntb++;
        }
    }
    ++cntb;
    if(cnta == 0) printf("-1");
    else printf("%d",cntb/cnta + ((cntb%cnta) ? 1:0));
    return 0;
}
