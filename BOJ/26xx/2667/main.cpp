#include<bits/stdc++.h>
using namespace std;
int yyy[4] = {0,0,1,-1}, xxx[4] = {1,-1,0,0};
int a[100][100];
int n;
vector<int> ans;
int dfs(int y,int x){
    a[y][x] = 0;
    int cnt = 0;
    for(int i=0;i<4;i++){
        int yy = y+yyy[i], xx = x+xxx[i];
        if(a[yy][xx]){
            cnt += dfs(yy,xx);
        }
    }
    return cnt + 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&a[i][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j])
                ans.push_back(dfs(i,j));
        }
    }
    printf("%d\n",(int)ans.size());
    sort(ans.begin(), ans.end());
    for(int x: ans)
        printf("%d\n",x);
    return 0;
}
