#include<bits/stdc++.h>
using namespace std;
typedef set<int> :: iterator it;
int n;
int a[510][510];
set<int> s;
void in(){
    int x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        a[x][y] = 1; s.insert(x); s.insert(y);
    }
}
void f(){
    for(int k=1;k<=500;k++){
        for(int i=1;i<=500;i++){
            if(a[i][k]==0) continue;
            for(int j=1;j<=500;j++){
                if(a[k][j]==0 || i==j || i==k || k==j) continue;
                if(a[i][j]==0 || a[i][j]>a[i][k]+a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
}
int main(){
    in();
    f();
    int hap = 0;
    for(it i=s.begin();i!=s.end();i++){
        for(it j=s.begin();j!=s.end();j++){
            hap += a[*i][*j];
        }
    }
    printf("%.3f",((double)hap)/(s.size()*(s.size()-1)));
    return 0;
}
