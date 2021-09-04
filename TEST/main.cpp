#include <bits/stdc++.h>

using namespace std;

struct algo
{
    int x,y;
};

bool cmp(algo a,algo b)
{
    return a.x<b.x || (a.x == b.x && a.y<b.y);
}

int main()
{
    int t,i,j,n,ans[100001],cnt[21];
    algo a[100001];
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            scanf("%d %d",&a[j].x,&a[j].y);
        }
        sort(a+1,a+n+1,cmp);
        for(j=1;j<n;j++){
            if(a[j].y>a[j+1].y)
                ans[j+1]=ans[j]+1;
        }
        sort(ans+1,ans+n+1);
        cnt[i]=ans[n];
    }
    for(i=t;i>=1;i--)
        printf("%d\n",cnt[i]);
    return 0;
}
