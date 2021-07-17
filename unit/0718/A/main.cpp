#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,l,ans,arr[100100];

int main(){
    scanf("%d %lld %lld",&n,&m,&l);
    for(int i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    sort(arr+1,arr+n+1);

    int left,right;
    ll sum=0LL;
    left=right=n;
    while(left<=right){
        if(sum<=m){
            if(left < right) ans = max(ans,sum);
            if(left>0 && arr[left]>=l) // 선생님 실력이 있나?
                sum+=arr[left--];
            else
                sum-=arr[right--];
        }else
            sum-=arr[right--];
    }
    printf("%lld",ans);
    return 0;
}

/*
특수 테케
1. 제일 실력이 좋은 선생이 L만족 안할 때
2. n==100000, L==1, m==100000, 모든 선생의 실력 == 1
3.

*/
