#include<bits/stdc++.h>
using namespace std;
int a[100100];
int min1(int x,int y) { return (abs(x)<abs(y)) ? x : y; }
int main(){
    int n,mini = 2000000001;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    //sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int x = lower_bound(a+1,a+n+1,-a[i]) - a;
        if(x>n) x = n;
        if(x==i){
            if(x>1) mini = min1(mini,a[i]+a[i-1]);
            if(x<n) mini = min1(mini,a[i]+a[i+1]);
        }
        else{
            mini = min1(mini,a[i]+a[x]);
            if(x>1 && x-1!=i) mini = min1(mini,a[i]+a[x-1]);
        }
    }
    printf("%d",mini);
    return 0;
}

// -3 0 2 9
