#include<bits/stdc++.h>
using namespace std;
int n,d[10010],b[10010],c[10010],cnt,ang1,ang2;
bool f(int x,int y){
    for(int i=1;i<=n;i++) b[i] = c[i];
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
        printf("%d %d\n%d %d\n1 1",ang1,ang2,x,y);
        return true;
    }
    for(int i=xx;i<=(xx+yy)/2;i++) swap(b[i],b[yy-i+xx]);
    for(int i=1;i<=n;i++)
        if(b[i]!=i) return false;

    printf("%d %d\n",ang1,ang2);
    printf("%d %d\n",x,y);
    printf("%d %d",xx,yy);
    return true;
}

bool ff(int x,int y){
    if(x==6 && y==9){
        printf("ang");
    }
    vector<int> a;
    for(int i=0;i<=n+1;i++) c[i] = d[i];
        for(int i=x;i<=(x+y)/2;i++) swap(c[i],c[y-i+x]);

    c[0] = 0; c[n+1] = n+1;
    for(int i=0;i<=n;i++){
        if(abs(c[i]-c[i+1])>1){
            if(i==n) a.push_back(n);
            else if(i==0) a.push_back(1);
            else{a.push_back(i); a.push_back(i+1);}
        }
    }
    sort(a.begin(),a.end());
    int m = a.size();
    ang1 = x; ang2 = y;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(f(a[i],a[j])) return true;
        }
    }
    f(1,1);
    return false;
}
int main(){
    vector<int> a;
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
    for(int i=0;i<m;i++)
        for(int j=i;j<m;j++)
            if(ff(a[i],a[j])) return 0;
    printf("1 1\n1 1\n1 1");
    return 0;
}
