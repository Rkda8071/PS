#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[110],b[210];

int main(){
    scanf("%d",&t);
    for(int x=1,i=0;i<30;i++){
        //printf("%d ",x);
        a[i] = x;
        x *= 2;
    }
    for(int chk=1,j=1,i=30;i<100;i++,j++){
        while(j == chk){
            chk *= 2;
            j++;
        }
        a[i] = j;
        //printf("%d ",j);
    }
    for(int tt = 1; tt<=t; tt++){
        fflush(stdout);
        ll sum = 0LL;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
        for(int i=0;i<n;i++){
            b[i] = a[i];
            scanf("%d",&b[i+n]);
            sum += (ll)b[i] + (ll)b[i+n];
        }
        sort(b+30,b+2*n);
        sum /= 2LL;
        ll chk = 0LL;
        for(int i=2*n-1;i>=30;i--){
            printf("%d ",b[i]);
            fflush(stdout);
            chk += b[i];
            if(sum - chk < (1<<30)){
                for(int j=0; j<30; j++){
                    if(((sum - chk) & (1LL<<j))){
                        printf("%d ", (1<<j));
                        fflush(stdout);
                    }
                }
                break;
            }
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}