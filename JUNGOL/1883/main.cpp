#include<bits/stdc++.h>
using namespace std;
char s[10010],e[10010];
int d[10010][11],chk[10010][11];

int main(){
    int n;
    scanf("%d",&n);
    scanf(" %s %s",s+1,e+1);
    // 왼쪽으로 돌리면 숫자 증가
    // 오른쪽으로 돌리면 감소

    int sp = 0;
    d[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++){ // 얼마나 돌아갔는지
            if(!d[i-1][j]) continue;
            int r,l;
            int ss = (s[i]-'0'+ 10 + j)%10,ee = e[i]-'0';
            if(ss>ee){
                r = ss-ee;
                l = (10 - r)%10;
            }else{
                l = ee-ss;
                r = (10 - l)%10;
            }
            int sp = (j+l+10) % 10;
            if(!d[i][sp] || d[i][sp]>d[i-1][j] + l){
                d[i][sp] = d[i-1][j] + l;
                chk[i][sp] = l;
            }
            //sp = (j-r+10) % 10;
            if(!d[i][j] || d[i][j]>d[i-1][j] + r){
                d[i][j] = d[i-1][j] + r;
                chk[i][j] = -r;
            }
        }
    }
    int x = 0;
    if(!d[n][0]) d[n][0] = 2000000000;
    for(int i=1;i<10;i++) if(d[n][i]>0 && d[n][x]>d[n][i]) x = i;
    printf("%d\n",d[n][x]-1);

    stack<int> dap;
    for(int i=n;i>=1;i--){
        dap.push(chk[i][x]);
        if(chk[i][x]>0) x = (x-chk[i][x]+10)%10;
    }
    int i = 1;
    while(!dap.empty()){
        printf("%d %d\n",i++,dap.top());
        dap.pop();
    }
    return 0;
}
