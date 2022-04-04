#include<bits/stdc++.h>
using namespace std;
// 다음섬 1
// 하나 뛰고 하나 2
// 빽 -1

// a[1]은 0까지 다 채우고 1에 있음
// a[2]은 1까지 다 채우고 2에 있음

// i칸에서 i+2칸으로 i+1칸으로 i+3칸으로 -> a[i]가 a[i+3]로
// a[i]가 a[i+1]로

int a[50100];
int main(){
    int n;
    scanf("%d",&n);
    a[0] = a[1] = a[2] = 1;

    for(int i=3;i<=n;i++){
        a[i] = a[i-1] + a[i-3];
        a[i] %= 1000000009;
    }
    printf("%d",a[n]);
}
