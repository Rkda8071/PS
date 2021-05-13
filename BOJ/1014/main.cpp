#include<bits/stdc++.h>
using namespace std;
int n,m,t;
char a[20][20];
int d[20][1<<10];
//d[세로][현재 단계에서의 비트마스크]

void init(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
            scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<m);j++)
            d[i][j] = -1;
    for(int j=0;j<(1<<m);j++)
        d[n][j] = 0;
}
bool chk(int i,int j){
    //금지된 좌석에 앉았나?
    //연속해서 앉았나?
    for(int l=0;l<m;l++){
        int x = (1<<l);
        if((j&x) == 0) continue; //l번째에는 안 앉음
        if((l>0 && (j&(x>>1)) || a[i][l] == 'x') // 불꽃가능
            return 0;
    }
    return 1;
}

void solve(){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<(1<<m);j++){ //i번째 층, j형태의 좌석
            if(!chk()) continue;
            int x = builtin_popcount(j);
            for(int l=0;l<(1<<m);l++){// 밑에서 가져올 층
                if(d[i+1][l] == -1) continue; //안 앉음
                //이전과 겹치는 비트가 있나?
                int ang = 0;
                for(int k=0;k<m;k++){
                    if((l&(1<<k)) &&
                       (((1<<(k-1)) | (1<<(k+1))) & j != 0))
                        ang = 1;
                }
                if(ang==0) d[i][j] = max(d[i][j],d[i+1][l]+x);
            }
        }
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        init();
        solve();
    }
    return 0;
}
