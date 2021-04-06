#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        int x,y,x1,y1,x2,y2;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);
        x = x-a+b;
        y = y-c+d;
        if(x1<=x && x<=x2 && y1<=y && y<=y2){
            if((a!=0 || b!=0) && x2-x1==0) printf("No\n");
            else if((c!=0 || d!=0) && y2-y1==0) printf("No\n");
            else printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
