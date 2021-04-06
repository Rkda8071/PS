#include<bits/stdc++.h>
using namespace std;
char a[200100];
int d[200100],n;
void mini(){
    int l,r,cnt = n;
    l = r = 1;
    for(int i=1;i<n;i++){
        if(a[i] == '<'){
            for(r=i+1;r<n;r++) if(a[r]=='>') break;
            for(int j=l;j<i;j++) d[j] = cnt--;
            for(int j=r;j>=i;j--) d[j] = cnt--;
            i = l = r + 1;
        }
    }
    for(int i=l;i<=n;i++) {d[i] = cnt--; printf("ang");}
    for(int i=1;i<=n;i++) printf("%d ",d[i]);
    puts("");
}
void maxim(){
    int l,r,cnt = n;
    l = r = n;
    for(int i=n-1;i>=1;i--){
        if(a[i] == '>'){
            for(l=i-1;l>=1;l--) if(a[l]=='<') break;
            for(int j=r;j>i+1;j--) d[j] = cnt--;
            for(int j=l+1;j<=i+1;j++) d[j] = cnt--;
            i = r = l;
        }
    }
    for(int i=r;i>=1;i--) d[i] = cnt--;
    for(int i=1;i<=n;i++) printf("%d ",d[i]);
    puts("");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        // 가장 적은 것 먼저
        scanf("%d",&n);
        scanf("%s",a+1);
        mini();
        maxim();
    }
    return 0;
}
