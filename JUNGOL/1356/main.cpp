#include<bits/stdc++.h>
using namespace std;
int n,d[10010],b[10010],cnt;
vector<int> a;
bool f(int x,int y){
    for(int i=1;i<=n;i++) b[i] = d[i];
    for(int i=x;i<=(x+y)/2;i++) swap(b[i],b[y-i+x]);
    int xx,yy;
    xx = yy = 0;
    for(int i=1;i<=n;i++){
        if(b[i]!=i) {
            if(!xx) xx=i;
            yy=i;
        }
    }
    if(xx==0 && yy==0){
        printf("%d %d\n1 1",x,y);
        return true;
    }
    for(int i=xx;i<=(xx+yy)/2;i++) swap(b[i],b[yy-i+xx]);
    for(int i=1;i<=n;i++)
        if(b[i]!=i) return false;

    printf("%d %d\n",x,y);
    printf("%d %d",xx,yy);
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    d[0] = 0; d[n+1] = n+1;
    for(int i=0;i<=n;i++){
        if(abs(d[i]-d[i+1])>1){
            if(i==n) a.push_back(n);
            else if(i==0) a.push_back(1);
            else{a.push_back(i); a.push_back(i+1);}
        }
    }
    sort(a.begin(),a.end());
    int m = a.size();
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(f(a[i],a[j])) return 0;
        }
    }
    printf("1 1\n1 1");
    return 0;
}
