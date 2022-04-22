#include<bits/stdc++.h>
using namespace std;
int chk[110],e,w,a[110][110],mini = 2000000000;

// 못품!
stack<int> s;
void f(int x,int cnt){
    if(x==e){
        mini = min(mini, cnt);
        return;
    }
    int ang = 0;
    for(int i=0;i<w;i++) if(chk[i] == a[x][i]) ang++;
    if(ang == w) f(x+1,cnt);
    for(int i=0;i<w;i++) while(chk[i] > a[x][i]){
        chk[s.top()]--; cnt++;
        s.pop();
    }

    for(int i=0;i<w;i++){
        if(chk[i] < a[x][i]){
            chk[i]++;
            s.push(i); f(x,cnt+1);
            chk[i]--;
        }
    }
    
}
int main(){
    int tt;
    scanf("%d",&tt);
    for(int t=1;t<=tt;t++){
        mini = 2000000000;
        scanf("%d %d",&e,&w);
        for(int i=0;i<e;i++){
            for(int j=0;j<w;j++)
                scanf("%d",&a[i][j]);
        }
        f(0,0);
        printf("Case #%d: %d",t,mini);
    }
}