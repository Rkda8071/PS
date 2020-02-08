#include<bits/stdc++.h>
using namespace std;
char a[40],ang[3] = {'+','-','.'};
int c,n;
int cal(int x,bool p){return p?x:-x;}
void f(int x,int hap,int cur,bool p){
    if(x==n){
        hap += cal(cur,p);
        if(hap == 0){
            if(++c<=20) {
                for(int i=1;i<n;i++) printf("%d %c ",i,a[i]);
                printf("%d",n);
                puts("");
            }
        }
        return;
    }
    a[x] = '+';
    f(x+1,hap+cal(cur,p),x+1,1);
    a[x] = '-';
    f(x+1,hap+cal(cur,p),x+1,0);
    a[x] = '.';
    if(x<9) f(x+1,hap,10*cur+x+1,p);
    else f(x+1,hap,100*cur+x+1,p);
}
int main(){
    scanf("%d",&n);
    f(1,0,1,true);
    printf("%d",c);
    return 0;
}
