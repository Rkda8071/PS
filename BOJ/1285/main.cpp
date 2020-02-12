#include<bits/stdc++.h>
using namespace std;
char a[30][30];
int chk,n;
int vchk(int x){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if((!(chk&(1<<(i-1))) && a[i][x] == 'T')
        || ((chk&(1<<(i-1))) && a[i][x] == 'H')) ++cnt;
    }
    return cnt;
}
int hchk(int x){
    int cnt = 0;
    for(int i=1;i<=n;i++) if(a[x][i] == 'T') ++cnt;
    return cnt;
}
int main(){
    //freopen("input.txt","r",stdin);
    int x,cnt,mini = 2000000000;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    while(chk<(1<<n)){
        cnt = 0;
        for(int i=1;i<=n;i++){
            x = vchk(i);
            if(x>n/2) cnt += n - x;
            else cnt += x;
        }
        mini = min(mini,cnt);
        ++chk;
    }
    printf("%d",mini);
    return 0;
}
