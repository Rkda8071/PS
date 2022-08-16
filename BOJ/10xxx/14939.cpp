#include<bits/stdc++.h>
using namespace std;
int a[20],d[20],n=10,cnt,ang,ans = 2000000000;
char b[20];

int main(){
    for(int i=0;i<n;i++){
        scanf(" %s",b);
        for(int j=n-1;j>=0;j--)
            d[i] = d[i]*2 + ((b[j] == 'O') ? 1 : 0);
    }
    for(int i=0;i<(1<<n);i++){
        cnt = 0;
        for(int j=0;j<n;j++)
            a[j] = d[j];
        
        for(int x=0;x<n;x++){
            if(i & (1<<x)){
                ++cnt;
                if(x>0) a[0] ^= (1<<(x-1));
                a[0] ^= (1<<x);
                if(x<n-1) a[0] ^= (1<<(x+1));
                a[1] ^= (1<<x);
            }
        }

        for(int y=1;y<n;y++){
            for(int x=0;x<n;x++){
                if(a[y-1] & (1<<x)){
                    ++cnt;
                    if(x>0) a[y] ^= (1<<(x-1));
                    a[y] ^= (1<<x);
                    if(x<n-1) a[y] ^= (1<<(x+1));
                    a[y+1] ^= (1<<x);
                }
            }
        }
        if(a[n-1] == 0)
            ans = min(ans, cnt);
    }
    if(ans == 2000000000) printf("-1");
    else printf("%d",ans);
    return 0;
}