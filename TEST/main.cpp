#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
int n,m;
int a[30],cnt[30];
int dap[10];
void f(int x){
    if(x==m+1){
        for(int i=1;i<=m;i++)
            printf("%c",dap[i] + 'a');
        puts("");
        return;
    }
    for(int i=0;i<26;i++){
        if(cnt[i]<a[i]){
            cnt[i]++;
            dap[x] = i;
            f(x+1);
            cnt[i]--;
            dap[x] = 0;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        char x;
        scanf(" %c",&x);
        a[x-'a']++;
    }
    //dap[0] = 0;
    f(1);
=======
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
>>>>>>> 697ebf68c1277f4c5f32a85f57d6164abbbb3da3
}
