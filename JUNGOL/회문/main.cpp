#include<bits/stdc++.h>
using namespace std;
char a[100100];
int f(int l,int r,int chk){
    if(l>=r) return chk;
    if(a[l]==a[r]) return f(l+1,r-1,chk);
    else if(chk == 0){
        int x,y;
        x = y = 2;
        if(a[l+1] == a[r]) x = f(l+2,r-1,1);
        if(a[l] == a[r-1]) y = f(l+1,r-2,1);
        return min(x,y);
    }
    return 2;
}
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",a+1);
        for(m=1;a[m+1]!=NULL;m++);
        printf("%d\n",f(1,m,0));
    }
    return 0;
}
