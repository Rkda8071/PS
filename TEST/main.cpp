#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[1000001],ar[1000001];
void f(int i,int sum){
   if(sum==1){
      return;
   }
   if((a[sum/3]>i||a[sum/3]==0)&&sum%3==0){
      ar[i]=sum/3;
      a[sum/3]=i+1;
      f(i+1,sum/3);
   }
   if((a[sum/2]>i||a[sum/2]==0)&&sum%2==0){
      ar[i]=sum/2;
      a[sum/2]=i+1;
      f(i+1,sum/2);
   }
   if(a[sum-1]>i||a[sum-1]==0){
      ar[i]=sum-1;
      a[sum-1]=i+1;
      f(i+1,sum-1);
   }
}
int main() {
   scanf("%d", &n);
   f(0,n);
   printf("%d\n%d ",a[1],n);
   for(int i=1;i>1;i=ar[i]){
      printf("%d ",ar[i]);
   }
    return 0;
}
