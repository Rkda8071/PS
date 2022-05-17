#include<bits/stdc++.h>
using namespace std;
int t,tt,r,ans;
int a[1000][1000];
void f(){
    ans = 0;
    for(int rr=1; rr<=r; rr++){
        for(int x=1; x<=rr; x++){
            int y = (int)round(sqrt(rr*rr - x*x));
            a[x][y] = a[y][x] = tt;
        }
    }
    for(int y=1;y<=r; y++){
        for(int x=1; x<=r; x++){
            if((int)round(sqrt(x*x + y*y)) <= r){
                //printf("0");
                if(a[y][x] != tt) {ans++; }//printf("[%d %d]\n",y,x);}
            }else{
                //printf("1");
                if(a[y][x] == tt) {ans++; }//printf("[%d %d]\n",y,x);}
            }
            
        }
        //puts("");
    }
}
int main(){
    scanf("%d",&t);
    for(tt=1; tt<=t; tt++){
        printf("Case #%d: ",tt);
        scanf("%d",&r);
        f();
        printf("%d\n",ans*4);
    }
}
