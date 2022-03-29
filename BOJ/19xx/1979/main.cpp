#include<bits/stdc++.h>
using namespace std;
int n,k,ang;
int ans[10][1000000];
int chk[10][100];
void f(int x,int m){
    ans[ang][x] = m/n;
    m = m%n;
    if(chk[ans[ang][x]][m] == ang || ans[ang][x]>9){
        ans[ang][0] = 2000000000;
        return;
    }
    chk[ans[ang][x]][m] = ang;
    if(ans[ang][x] == k && m==0){
        ans[ang][0] = x;
        return;
    }
    f(x+1,m*10+ans[ang][x]);
}
int main(){
    int i=1;
    ans[1][0] = 1;
    scanf("%d %d",&n,&k); // n극적인, 마지막 k
    if(n==1){
        printf("%d",k);
        return 0;
    }
    while(1){
        if(k-n*i < 0) break;
        ang = i;
        ans[ang][1] = i;
        f(2,(k-n*i)*10+i);
        i++;
    }
    int mini = 1;
    for(int i=2;i<=ang;i++){
        if(ans[i][0] < ans[mini][0])
            mini = i;
    }
    if(ans[mini][0] == 2000000000){
        printf("0");
    }else{
        for(int i=1;i<=ans[mini][0];i++)
            printf("%d",ans[mini][i]);
    }
    return 0;
}

//1020408163265
//5102040816326
