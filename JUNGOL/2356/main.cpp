#include<bits/stdc++.h>
using namespace std;
int c,n;
int a[50],b[50];
int d[1<<15][50];
int main(){
    scanf("%d %d",&c,&n); // 물통 용량, 물통 개수
    for(int i=0;i<n;i++) scanf("%d",&a[i]); // 담긴 물
    for(int i=0;i<=c;i++) scanf("%d",&b[i]); // 얼마
    for(int i=0;i<n;i++) d[1<<i][a[i]] = 1;

    for(int i=1;i<(1<<n);i++){
        for(int cur=0;cur<=c;cur++){ // 비교할 용량
            for(int j=0;j<n;j++){   // 추가할 물통
                if(!(i&(1<<j))) continue;
                int ang = i^(1<<j);
                if(!d[ang][cur]) continue;

                if(!d[i][a[j]] || d[i][a[j]]<d[ang][cur] + b[cur])
                    d[i][a[j]] = d[ang][cur] + b[cur];

                if(!d[i][cur] || d[i][cur]<d[ang][cur] + b[a[j]])
                    d[i][cur] = d[ang][cur] + b[a[j]];

                int x,y; // a[j]랑 cur이랑 섞음
                x = min(a[j]+cur,c);
                y = a[j]+cur - x;
                if(!d[i][x] || d[i][x]<d[ang][cur] + b[y])
                    d[i][x] = d[ang][cur] + b[y];
                if(!d[i][y] || d[i][y]<d[ang][cur] + b[x])
                    d[i][y] = d[ang][cur] + b[x];
            }
        }
    }
    int dap = 0;
    for(int i=0;i<=c;i++)
        if(d[(1<<n)-1][i])
            dap = max(dap,d[(1<<n)-1][i] + b[i]);

    printf("%d",dap-1);
    return 0;
}
