#include<bits/stdc++.h>
using namespace std;
int d[100100][5];
int f(int x,int y){
    if(x==y) return 1;
    else if(x==0 || y==0) return 2;
    else if((x+y)%2) return 3;
    else return 4;
}
int main(){
    int x,y=0,c=0;
    scanf("%d",&x);
    d[0][0] = 2; y = x;
    while(1){
        scanf("%d",&x);
        if(x==0) break;
        for(int i=0;i<=4;i++){
            if(d[c][i]){
                if(d[c+1][y] == 0 || d[c+1][y]>d[c][i] + f(i,x))
                    d[c+1][y] = d[c][i] + f(i,x);
                if(d[c+1][i] == 0 || d[c+1][i]>d[c][i] + f(y,x))
                    d[c+1][i] = d[c][i] + f(y,x);
            }
        }
        ++c; y=x;
    }
    int mini = 2000000000;
    for(int i=0;i<=4;i++){
        if(d[c][i]) mini = min(mini,d[c][i]);
    }
    printf("%d",mini);
    return 0;
}
