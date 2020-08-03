#include<bits/stdc++.h>
using namespace std;
typedef tuple<double,double> tp;
tp a[101];
double d[101][101];
double dis(int x,int y){
    double x1,y1,x2,y2;
    tie(x1,y1) = a[x]; tie(x2,y2) = a[y];
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main(){
    int n;
    double x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&x,&y);
        a[i] = tp(x,y);
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j] = 2000000000;
    sort(a+1,a+n+1);

    d[1][2] = dis(1,2);
    d[2][1] = dis(1,2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++) d[i][i+1] = min(d[i][i+1],d[i][j]+dis(j,i+1));
        for(int j=i+2;j<=n;j++) d[i][j] = min(d[i][j], d[i][j-1] + dis(j-1,j));

        for(int j=1;j<i;j++) d[i+1][i] = min(d[i+1][i],d[j][i]+dis(j,i+1));
        for(int j=i+2;j<=n;j++) d[j][i] = min(d[j][i], d[j-1][i] + dis(j-1,j));
    }
    double mini = 2000000000;
    for(int i=1;i<=n;i++) mini = min(mini,min(d[n][i],d[i][n]) + dis(i,n));
    printf("%.2f",mini);
    return 0;
}
