#include <iostream>

using namespace std;
int a[310][310];
int n,m,k;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tmp;
            scanf("%d",&tmp);
            a[i][j] = a[i-1][j] + a[i][j-1] -a[i-1][j-1] + tmp;
        }
    }
    scanf("%d",&k);
    while(k--){
        int sx,sy,ex,ey;
        scanf("%d %d %d %d",&sy,&sx,&ey,&ex);
        printf("%d\n",a[ey][ex] - a[sy-1][ex] - a[ey][sx-1] + a[sy-1][sx-1]);
    }
    return 0;
}
