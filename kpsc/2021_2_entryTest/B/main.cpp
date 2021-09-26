#include<bits/stdc++.h>
using namespace std;
int n,m,d[10010];
char a[10010][110];
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %s",a[i]+1);
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        int hap = 0;
        for(int j=strlen(a[i]+1); j>0; j--)
            if('0' <= a[i][j] && a[i][j] <= '9')
                hap += a[i][j] - '0';
        d[i] = d[i-1] + hap;
    }
}
int main(){
    init();
    while(m--){
        int sx,sy,ex,ey,e,hap=0;
        scanf("%d %d %d %d %d",&sx,&sy,&ex,&ey,&e);
        if(ex<sx || (ex==sx && ey<sy)){swap(ex,sx);swap(ey,sy);}

        for(int i=sy; i<=strlen(a[sx]+1); i++){
            if('0' <= a[sx][i] && a[sx][i] <= '9')
                hap += a[sx][i] - '0';
        }
        for(int i=1; i<=ey; i++){
            if('0' <= a[ex][i] && a[ex][i] <= '9')
                hap += a[ex][i] - '0';
        }
        int dap = hap + (d[ex-1] - d[sx]);
        if(dap == e)
            printf("CORRECT\n");
        else
            printf("WRONG\n");
    }
    return 0;
}

