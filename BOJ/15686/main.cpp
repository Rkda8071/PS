#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
vector<p> c,h;
int a[60][60],chk[20];
int n,m,mini=2000000000;
int dis(p x, p y){
    return abs(get<0>(x)-get<0>(y)) + abs(get<1>(x)-get<1>(y));
}
int hap(){
    int k = 0;
    for(int i=0;i<h.size();i++){
        int ang = 2000000000;
        for(int j=0;j<m;j++)
            ang = min(ang,dis(h[i],c[chk[j+1]]));
        k += ang;
    }
    return k;
}

void f(int x){
    if(x==m+1){
        mini = min(mini,hap());

        return;
    }
    for(int i=chk[x-1]+1; i<c.size(); i++){
        chk[x] = i;
        f(x+1);
        chk[x] = 0;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] == 1)
                h.push_back(p(i,j)); // 집 추가
            else if(a[i][j] == 2)
                c.push_back(p(i,j)); // 치킨집 추가
        }
    }
    chk[0] = -1;
    m = min(m,(int)(c.size()));
    f(1);
    printf("%d",mini);
    return 0;
}
