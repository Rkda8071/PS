#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    int x,r,p;
}a[510];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[i] = {x,y,z};
    }
    if(a[2].p && a[2].r>=a[1].x) d[1][2] = 1;
    if(a[2].r>=a[1].x) d[2][1] = 1;
    for(int i=1;i<=n;i++){
        if(a[i].p){
            for(int j=1;j<i;j++) // 돌아오는 길
                if(a[i].x-a[j].x<=a[i].r) d[i+1][i] += d[i][j];
            for(int j=i+2;j<=n;j++)
                if(a[j].p && a[j].x-a[i].x<=a[j].r)
                    d[i][j] += d[i+1][i];
        }
        for(int j=1;j<i;j++){ // 가는 길
            for(int j=1;j<i;j++) // 돌아오는 길
                if(a[i].x-a[j].x<=a[i].r) d[i][i+1] += d[j][i];
            for(int j=i+2;j<=n;j++)
                if(a[j].p && a[j].x-a[i].x<=a[j].r)
                    d[j][i] += d[i][i+1];
        }
    }
    int hap =0;

}
