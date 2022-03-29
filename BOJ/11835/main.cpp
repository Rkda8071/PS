#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d3[10100],d5[10100],d7[10100],hap;
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&d3[i]);
    for(int i=1;i<=n;i++){
        d5[i] = min(d3[i-1],d3[i]); d3[i-1] -= d5[i]; d3[i] -= d5[i];
        d7[i] = min(d5[i-1],d3[i]); d5[i-1] -= d7[i]; d3[i] -= d7[i];
    }
    for(int i=1;i<=n;i++) hap += d3[i]*3 + d5[i]*5 + d7[i]*7;
    printf("%lld",hap);
}
