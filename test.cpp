#include<bits/stdc++.h>
using namespace std;

pair<int, int> p;
tuple<int, int, int> tp;

int a[100],n;
int main(){
    scanf("%d",&n);          // n 입력
    for(int i=0; i<n; i++) 
            scanf("%d",&a[i]);   // a배열에 n개 입력

    for(int i=0; i<n; i++) printf("%d ", a[i]); // 배열 출력

    sort(a, a+n, greater<int>());     // 배열 오름차순으로 정렬
    puts("");                // 줄 바꿈
    for(int i=0; i<n; i++) printf("%d ", a[i]); // 정렬된 배열 출력
}