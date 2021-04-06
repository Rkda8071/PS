#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int> tp;
int n,m,dap,cnt;
vector<int> a[210];
int imsi[210][210];
int chk[210];
// 1부터 n으로 가야함
int f(int x,int ang){
    if(x == n) return ang;
    for(int i : a[x]){
        if(imsi[x][i] && chk[i]!=cnt){
            int z = imsi[x][i];
            chk[i] = cnt;
            int b = f(i,min(ang,z));
            //chk[i] = 0;
            if(b){
                imsi[x][i] -= b; imsi[i][x] += b;
                return b;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        imsi[x][y] += z;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(imsi[i][j]){
                if(!imsi[j][i]) a[j].push_back(i);
                a[i].push_back(j);
            }
        }
    }
    int ang = 0;
    for(int i : a[1]){
        while(imsi[1][i]){
            chk[1] = chk[i] = ++cnt;
            ang = f(i,imsi[1][i]);

            if(ang){
                imsi[1][i] -= ang;
                imsi[i][1] += ang;
                dap += ang;
            }else break;
        }
    }
    printf("%d",dap);
    return 0;
}
