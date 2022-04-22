#include<bits/stdc++.h>
using namespace std;
int r,c;
void f(int y){
    if(y==r) {
        for(int i=0;i<c;i++) printf("+-"); printf("+\n");
        return;
    }
    if(y==0){
        printf("..");
        for(int i=1;i<c;i++) printf("+-"); printf("+\n");
        printf("..");
        for(int i=1;i<c;i++) printf("|."); printf("|\n");
    }else{
        for(int i=0;i<c;i++) printf("+-"); printf("+\n");
        for(int i=0;i<c;i++) printf("|."); printf("|\n");
    }
    f(y+1);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d %d",&r,&c);
        printf("Case #%d:\n",i);
        f(0);
    }
}
