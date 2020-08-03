#include<bits/stdc++.h>
using namespace std;

int a[11],b[11];
int n =10,aa,bb;
int main(){
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]) ++aa;
        else if(b[i]>a[i]) ++bb;
    }
    if(aa>bb) printf("A");
    else if(bb>aa) printf("B");
    else printf("D");
}
