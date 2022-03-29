#include<bits/stdc++.h>
using namespace std;
int n,k,s,a[100010],cur,m,ans;
int main(){
    scanf("%d %d %d",&n,&k,&s); //아파트 수, 버스 정원, 학교 위치
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x] = y;
    }

    cur = 0;
    for(int i=0;i<s;i++){
        while(a[i]){
            if(cur==0)
                ans += abs(s-i)*2;
            --a[i]; cur++;
            if(cur == k) cur = 0;
        }
    }
    cur = 0;
    for(int i=100000;i>s;i--){
        while(a[i]){
            if(cur==0)
                ans += abs(s-i)*2;
            --a[i]; cur++;
            if(cur == k) cur = 0;
        }
    }
    printf("%d",ans);
    return 0;
}
