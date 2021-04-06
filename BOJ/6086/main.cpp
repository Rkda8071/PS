#include<bits/stdc++.h>
using namespace std;
int n = 52,m;
int imsi[100][100],chk[100],cnt,dap;
vector<int> a[100];
void init(){
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        char xx,yy; int x,y,z;
        scanf(" %c %c %d",&xx,&yy,&z);
        if('A'<=xx && xx<='Z') x = xx - 'A';
        else x = xx - 'a' + 26;
        if('A'<=yy && yy<='Z') y = yy - 'A';
        else y = yy - 'a' + 26;
        imsi[x][y] += z;
        imsi[y][x] += z;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(imsi[i][j]){
                a[i].push_back(j);
                if(!imsi[j][i]) a[j].push_back(i);
            }
        }
    }
}
int f(int x,int ang){
    if(x=='Z'-'A') return ang;
    for(int i : a[x]){
        if(imsi[x][i] && chk[i]!=cnt){
            chk[i] = cnt;
            int y = f(i,min(ang,imsi[x][i]));
            if(y){
                imsi[x][i] -= y;
                imsi[i][x] += y;
                return y;
            }else chk[i] = 0;
        }
    }
    return 0;
}
int main(){
    init();
    for(int i : a[0]){
        while(imsi[0][i]){
            chk[0] = chk[i] = ++cnt;
            int ang = f(i,imsi[0][i]);
            if(ang){
                imsi[0][i] -= ang;
                imsi[i][0] += ang;
                dap += ang;
            }else break;
        }
    }
    printf("%d",dap);
    return 0;
}
