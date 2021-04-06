#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a[1000010];
int d[1000010][2],chk[1000010];
void f(int x){
    d[x][0] = 0;
    d[x][1] = 1;
    for(int i=a[x].size()-1;i>=0;i--){
        if(!chk[a[x][i]]){
            chk[a[x][i]] = 1;
            f(a[x][i]);
            d[x][0] += d[a[x][i]][1]; // 나는 얼리가 아니다
            d[x][1] += min(d[a[x][i]][1],d[a[x][i]][0]);
        }
    }
}
int main(){
    int x,y;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        //if(x>y) swap(x,y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    chk[1] = 1;
    f(1);
    printf("%d",min(d[1][0],d[1][1]));
    return 0;
}
