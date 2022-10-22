#include<bits/stdc++.h>
using namespace std;
char a[200100];
int n,cnt;
int main(){
    scanf("%d %s",&n,a+1);
    for(int i=1;i<=n/2;i++)
        cnt += (a[i] == 's') ? 1 : 0;
    if(cnt == n/4) printf("1\n%d",n/2);
    else{
        for(int i=n/2+1;i<=n;i++){
            cnt -= (a[i-n/2] == 's') ? 1 : 0;
            cnt += (a[i] == 's') ? 1 : 0;
            if(cnt == n/4){
                printf("2\n%d %d",i-n/2,i);
                break;
            }
            
        }
    }
}