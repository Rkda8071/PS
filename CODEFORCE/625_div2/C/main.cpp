#include<bits/stdc++.h>
using namespace std;
int n,maxim,cnt;
char a[110];
int l[110],r[110],chk[110];
void f(int x,int cut){
    maxim = max(maxim,x);
    r[l[cut]] = r[cut]; //자르는 곳의 왼쪽의 오른쪽이 자르는 곳의 오른쪽
    l[r[cut]] = l[cut]; // 똑같다  tq

    r[l[cut]] = cut;
    l[r[cut]] = cut;
}
int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    for(int i=1;i<=n;i++) l[i] = i-1;
    for(int i=1;i<=n;i++) r[i] = i+1;

    for(int i=1;i<=n;i++)
        if(a[i] == a[l[i]]+1 || a[i] == a[r[i]]+1) chk[i] = 1;
    for(int i=1;i<=n;i++) if(chk[i]) f(1,i);
    return 0;
}
