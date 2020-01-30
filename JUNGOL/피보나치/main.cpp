/*#include<bits/stdc++.h>
using namespace std;
struct A{
    int a[2][2];
};
A g(A x,A y){
    A a;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a.a[i][j] = x.a[i][0] * y.a[0][j] + x.a[i][1] * y.a[1][j];
            a.a[i][j] = a.a[i][j] % 10000;
        }
    }
    return a;
}
A f(A x,int n){
    if(n==0) return {0,0,0,0};
    if(n==1) return x;
    if(n%2) return g(f(g(x,x),n/2),x);
    else return f(g(x,x),n/2);
}
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==-1) break;
        printf("%d\n",f({1,1,1,0},n).a[0][1]);
    }
}*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A{
    ll a[2][2];
};
A g(A x,A y){
    A a;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a.a[i][j] = x.a[i][0] * y.a[0][j] + x.a[i][1] * y.a[1][j];
            a.a[i][j] = a.a[i][j] % 1000000;
        }
    }
    return a;
}
A f(A x,ll n){
    if(n==0) return {0,0,0,0};
    if(n==1) return x;
    if(n%2==1) return g(f(g(x,x),n/2),x);
    else return f(g(x,x),n/2);
}
int main(){
    ll n;
    scanf("%lld",&n);
    printf("%d",f({1,1,1,0},n).a[0][1]);
}

