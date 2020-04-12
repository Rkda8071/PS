#include<bits/stdc++.h>
using namespace std;
int n, a[1010];
int l1,l2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) a[i+n] = a[i];
    int xx,yy;
    xx=yy=0;
    for(int i=1;i<n*2;i++){
        if(!xx && abs(a[i]-a[i+1])>1){
            if(a[i]==n && a[i+1]==1) continue;
            xx = i+1;
        }
        else if(!yy && (abs(a[i]-a[i+1])>1 || a[i+1]==a[xx])){
            if(a[i+1]!=a[xx] && a[i]==1 && a[i+1]==n) continue;
            yy = i; break;
        }
    }
    /*1 2 3 4 5 6 7 8 9 10 - l1 9¹ø
    10 1 2 3 4 5 6 7 8 9 - 1~3
    2 1 10 3 4 5 6 7 8 9 - l2 9¹ø
    9 2 1 10 3 4 5 6 7 8
    l1 = a[yy]-1
    1 ~ yy-xx+1
    l2 = n-xx;*/
    /*1 2 3 4 5
    1 2 3 4 5
    4 5 1 2 3*/
    if(xx==0 && yy==0){
        printf("0\n");
        printf("1 1\n");
        printf("%d",a[1]-1);
    }else{
        printf("%d\n",(a[yy]-1)%n);
        printf("1 %d\n",yy-xx+1);
        printf("%d",(n-xx+1)%n);
    }
    return 0;
}
