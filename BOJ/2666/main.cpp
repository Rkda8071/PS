#include<bits/stdc++.h>
using namespace std;

int a[21],d[21][21];
// d[x1�� ��ġ][x2�� ��ġ]
int n,m,x1,x2;
int main(){
    scanf("%d %d %d %d",&n,&x1,&x2,&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);

    d[1][0] = abs(a[1] - x1); //x1�� 1��° ���幮���� �̵�
    d[0][1] = abs(a[1] - x2); //x2�� 1��° ���幮���� �̵�

    for(int i=1;i<=m;i++){
        d[i][i-1] = abs(x1-a[i]) + d[0][i-1];
        for(int j=1;j<i-1;j++) //d[i][i-1]�� �ּڰ� �ֱ�
            d[i][i-1] = min(d[i][i-1], abs(a[j]-a[i]) + d[j][i-1]);
        for(int j=i+1;j<=m;j++) //d[i+1 ~ m][i-1]�� ���ֱ�
            d[j][i-1] = d[j-1][i-1] + abs(a[j]-a[j-1]);

        d[i-1][i] = abs(x2-a[i]) + d[i-1][0];
        for(int j=1;j<i-1;j++) //d[i-1][i]�� �ּڰ� �ֱ�
            d[i-1][i] = min(d[i-1][i], abs(a[j]-a[i]) + d[i-1][j]);
        for(int j=i+1;j<=m;j++) //d[i-1][i+1 ~ m]�� ���ֱ�
            d[i-1][j] = d[i-1][j-1] + abs(a[j]-a[j-1]);
    }
    int dap = 2000000000;
    for(int i=0;i<m;i++)
        dap = min(dap,min(d[i][m],d[m][i]));

    printf("%d",dap);
    return 0;
}
