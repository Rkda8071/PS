#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int n,q,cnt=0;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) if(a[i]) cnt++;
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==1){
            if(a[y]==0){a[y]=1; cnt++;}
            else {a[y]=0; cnt--;}
        }else{
            if(y<=cnt) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
