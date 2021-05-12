#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,flag=0,a[1000001],cnt;
void f(int i,int sum) {
   if(i!=0&&i==flag&&sum != 1) return;
   if (sum == 1) {
      flag=i;
      return;
   }
   if (sum % 3 == 0) {
      a[i]=sum/3;
      f(i + 1, sum / 3);
   }
   if (sum % 2 == 0) {
      a[i]=sum/2;
      f(i + 1, sum / 2);
   }
   a[i]=sum-1;
   f(i + 1, sum - 1);
}
int main() {
   scanf("%d", &n);
   f(0,n);
   printf("%d\n",flag);
    return 0;
}
