#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int f[n+1] = {0};
    f[0] = 0; f[1] = 1;
    for(int i=2;i<=n;i++)
        f[i] = f[i-1] + f[i-2];
    printf("%d",f[n]);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int f,a,b;
    a = 1; b = 0; // a = f1, b = f0
    for(int i=2;i<=n;i++){
        f = a + b;
        b = a;
        a = f;
    }
    printf("%d",f);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct MATRIX{
    ll a[2][2]; // 青纺 备己 夸家
};
MATRIX product(MATRIX x,MATRIX y){
    MATRIX matrix;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            matrix.a[i][j] = x.a[i][0] * y.a[0][j] + x.a[i][1] * y.a[1][j];
            matrix.a[i][j] = matrix.a[i][j] % 1000000;
        }
    }
    return matrix;
}
MATRIX f(MATRIX x,ll n){
    if(n==0) return {0,0,0,0};
    if(n==1) return x;
    if(n%2==1) return product(f(product(x,x),n/2),x);
    else return f(product(x,x),n/2);
}
int main(){
    ll n;
    scanf("%lld",&n);
    printf("%d",f({1,1,1,0},n).a[0][1]);
}
