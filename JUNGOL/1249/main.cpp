#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

int n;
int a[30][30];
int d[1<<21],chk[1<<21];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    for(int x=1;x<(1<<n);x++){
        d[x] = INF;
        int cnt = -1, imsi = x;
        while(imsi){
            cnt += imsi%2;
            imsi/=2;
        }
        for(int i=0;i<n;i++){
            if((x&(1<<i))){
                int ang = x^(1<<i);
                if(d[x]>d[ang] + a[cnt][i]){
                    d[x] = d[ang] + a[cnt][i];
                    chk[x] = i;
                }
            }
        }
    }
    printf("%d\n",d[(1<<n)-1]);
    int ang = (1<<n)-1;
    stack<int> s;
    while(ang){
        //printf("%d ",chk[ang]+1);
        s.push(chk[ang]+1);
        ang -= (1<<chk[ang]);
    }
    while(!s.empty()){
        printf("%d ",s.top()); s.pop();
    }
    return 0;
}
