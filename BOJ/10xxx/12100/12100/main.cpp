#include<bits/stdc++.h>
using namespace std;
int n;
int a[30][30],dap
;
void f(int cnt){
    if(cnt == 5){
        for(int y=1;y<=n;y++) for(int x=1;x<=n;x++) dap = max(dap,a[y][x]);
        return;
    }
    int cur[30][30]={0};
    for(int y=0;y<=n+1;y++) for(int x=0;x<=n+1;x++) cur[y][x] = a[y][x];
    // 아래키
    for(int x=1;x<=n;x++){
        int ang = n+1, ang2 = 0;
        for(int y=n;y>=1;y--){
            if(a[y][x]){
                if(a[ang][x] == a[y][x] && !ang2){
                    a[ang][x] = a[y][x]*2;
                    ang2 = 1;
                }
                else{
                    a[ang-1][x] = a[y][x];
                    ang--; ang2 = 0;
                }
                if(ang!=y) a[y][x] = 0;
            }
        }
    }
    f(cnt+1);
    for(int y=1;y<=n;y++) for(int x=1;x<=n;x++) a[y][x] = cur[y][x];
    // 위키

    for(int x=1;x<=n;x++){
        int ang = 0,ang2 = 0;
        for(int y=1;y<=n;y++){
            if(a[y][x]){
                if(a[ang][x] == a[y][x] && !ang2){
                    a[ang][x] = a[y][x]*2;
                    ang2 = 1;
                }
                else{
                    a[ang+1][x] = a[y][x];
                    ang++; ang2 = 0;
                }
                if(ang!=y) a[y][x] = 0;
            }
        }
    }

    f(cnt+1);

    for(int y=1;y<=n;y++) for(int x=1;x<=n;x++) a[y][x] = cur[y][x];
    // 오른쪽키

    for(int y=1;y<=n;y++){
        int ang = n+1,ang2 = 0;
        for(int x=n;x>=1;x--){
            if(a[y][x]){
                if(a[y][ang] == a[y][x] && !ang2){
                    a[y][ang] = a[y][x]*2;
                    ang2 = 1;
                }
                else{
                    a[y][ang-1] = a[y][x];
                    ang--; ang2 = 0;
                }
                if(ang!=x) a[y][x] = 0;
            }
        }
    }
    f(cnt+1);

    for(int y=1;y<=n;y++) for(int x=1;x<=n;x++) a[y][x] = cur[y][x];
    // 왼쪽키
    for(int y=1;y<=n;y++){
        int ang = 0,ang2 = 0;
        for(int x=1;x<=n;x++){
            if(a[y][x]){
                if(a[y][ang] == a[y][x] && !ang2){
                    a[y][ang] = a[y][x]*2;
                    ang2 = 1;
                }
                else{
                    a[y][ang+1] = a[y][x];
                    ang++; ang2 = 0;
                }
                if(ang!=x) a[y][x] = 0;
            }
        }
    }
    f(cnt+1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    f(0);
    printf("%d",dap);
    return 0;
}
