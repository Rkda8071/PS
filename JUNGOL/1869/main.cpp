#include<bits/stdc++.h>
using namespace std;
typedef tuple <int,int> tp;
int a[1010];
int n,m,k;
vector<tp> b[510];
int d[1010][510];
int f(char x){
    if(x == 'R') return 1;
    else if(x=='G') return 2;
    else return 3;
}
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char x;
        scanf(" %c",&x);
        a[i] = f(x);
    }
    scanf("%d %d",&m,&k);
    for(int i=1;i<=k;i++){
        int x,y; char z;
        scanf("%d %d %c",&x,&y,&z);
        b[x].push_back(tp(y,f(z)));
        b[y].push_back(tp(x,f(z)));
    }
    d[0][1] = 1; //0번 카드 1번 마을
}
int main(){
    init();
    for(int i=1;i<=n;i++){ // i 횟수
        for(int j=1;j<=m;j++){ // j 마을
            if(d[i-1][j]){
                for(tp l : b[j]){
                    int x,y; tie(x,y) = l;
                    if(y==a[i]) d[i][x] = max(d[i][x],d[i-1][j] + 10);
                    else d[i][x] = max(d[i][x],d[i-1][j]);
                }
            }
        }
    }
    int dap = 0;
    for(int i=1;i<=m;i++) dap = max(dap,d[n][i]);
    printf("%d",max(0,dap-1));
    return 0;
}
