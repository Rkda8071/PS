#include<bits/stdc++.h>
using namespace std;
int t,x,y,mini=0;
int f(int s,int e){
    int maxim = 0,chk = 0;
    if(s==0 && e==0) return 0;
    for(int i=30;i>0;i--){
        int ang = (1<<i) - 1;
        if(ang<=e){
            maxim = max(maxim,f(max(0,s-ang),e-ang)+i);
            e = ang - 1;
            if(++chk==2 || s>e) break;
        }
    }
    return maxim;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}
