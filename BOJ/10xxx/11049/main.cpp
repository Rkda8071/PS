#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    int x,y;
}a[550];
int d[550][550];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    for(int k=1;k<n;k++){
        for(int s=1;s<=n;s++){
            int e = s+k;
            if(n<e) continue;
            d[s][e] = 2000000000;
            for(int i=s;i<e;i++){
                d[s][e] = min(d[s][e],
                    d[s][i] + d[i+1][e] + (a[s].x * a[e].y * a[i].y));
            }
        }
    }
    printf("%d",d[1][n]);
    return 0;

}
