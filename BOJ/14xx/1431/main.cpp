#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    int hap,len;
    char s[51];
    bool operator < (const A& x){
        if(x.len!=len) return len<x.len;
        if(x.hap!=hap) return hap<x.hap;
        return strcmp(s+1, x.s+1)<0;
    }
}a[1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",a[i].s+1); // 입력

        int m = strlen(a[i].s+1); // 문자열의 길이
        a[i].len = m;
        a[i].hap = 0;
        for(int j=1;j<=m;j++) // 숫자들의 합 구하기
            if('0' <= a[i].s[j] && a[i].s[j] <= '9')
                a[i].hap += a[i].s[j] - '0';
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        printf("%s\n",a[i].s+1);
    return 0;
}
