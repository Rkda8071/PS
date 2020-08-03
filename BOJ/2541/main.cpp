#include<bits/stdc++.h>
using namespace std;

int a,b;
int f(){
    int x,y;
    scanf("%d %d",&x,&y);
    if(a==b){
        if(x==y) return 1;
        else return 0;
    }else if(a>b){
        if(x>y) return 1;
        else return 0;
    }else{ // b>a
        if(y>x) return 1;
        else return 0;
    }
}
int main(){
    scanf("%d %d",&a,&b);
    int i=5;
    while(i--){
        if(f()) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
