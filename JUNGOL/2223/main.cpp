#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tp;
int n,m,b;
int d[510];
tp a[5300];
void init(){
    int s,e,t;
    scanf("%d %d %d",&n,&m,&b);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&s,&e,&t);
        a[i*2] = tp(s,e,t);
        a[i*2+1] = tp(e,s,t);
    }
    for(int i=0;i<b;i++){
        scanf("%d %d %d",&s,&e,&t);
        a[m*2+i] = tp(s,e,-t);
    }
}
bool bf(){
    int x,y,z;
    for(int k=1;k<=n;k++){
        for(int i=0;i<m*2+b;i++){
            tie(x,y,z) = a[i];
            if(d[y]>d[x]+z){
                d[y] = d[x]+z;
                if(k==n) return true;
            }
        }
    }
    return false;
}
int main(){
    int f;
    scanf("%d",&f);
    while(f--){
        init();
        printf("%s\n",bf()?"YES":"NO");
    }
    return 0;
}
