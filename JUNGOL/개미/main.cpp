#include<bits/stdc++.h>
using namespace std;
int w,h,a,b,ang;
int x,y,xx,yy;
int t,tt=0,chk;
int main(){
    scanf("%d %d %d %d %d",&w,&h,&a,&b,&t);
    x = (a+t) % (w*2);
    y = (b+t) % (h*2);
    printf("%d ",(x > w) ? w*2-x : x);
    printf("%d",(y > h) ? h*2-y : y);
    return 0;
}
