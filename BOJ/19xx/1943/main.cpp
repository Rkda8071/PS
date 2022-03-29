#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=3;
    while(t--){
        int n,hap=0;
        vector<int> a;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            for(int j=0;j<y;j++){
                hap += x;
                a.push_back(x);
            }
        }
        if(hap%2){
            printf("0\n");
            continue;
        }
        int dp[50100] = {0}, ang = 0;
        dp[0] = 1;
        sort(a.begin(), a.end());
        for(auto i=a.begin(); i!=a.end(); i++){
            ang += (*i);
            for(int j=min(ang,hap/2); j>=(*i); j--){
                if(dp[j-(*i)]){
                    dp[j] = 1;
                }
            }
            if(dp[hap/2]) break;
        }
        printf("%d\n",dp[hap/2]);
    }
    return 0;
}
