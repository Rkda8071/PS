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
            if(left>0 && arr[left]>=l) // ������ �Ƿ��� �ֳ�?
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
Ư�� ����
1. ���� �Ƿ��� ���� ������ L���� ���� ��
2. n==100000, L==1, m==100000, ��� ������ �Ƿ� == 1
3.

*/
