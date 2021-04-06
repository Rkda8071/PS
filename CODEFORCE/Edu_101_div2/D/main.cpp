#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main(){
    // 200000, 59^3, 8^2
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n>59){
            printf("%d\n",n+3);
            for(int i=n-1;i>=3;i--)
                if(i!=59 && i!=8 && i!=4) printf("%d %d\n",i,n);
            //n, 59, 8, 4 ³²À½
            for(int i=0;i<3;i++) printf("%d 59\n",n);
            for(int i=0;i<2;i++) printf("59 8\n");
            for(int i=0;i<2;i++) printf("8 4\n");
            for(int i=0;i<2;i++) printf("4 2\n");
        }else if(n>8){
            printf("%d\n",n+1);
            for(int i=n-1;i>=3;i--)
                if(i!=8 && i!=4) printf("%d %d\n",i,n);
            for(int i=0;i<2;i++) printf("%d 8\n",n);
            for(int i=0;i<2;i++) printf("8 4\n");
            for(int i=0;i<2;i++) printf("4 2\n");
        }else if(n>4){
            printf("%d\n",n);
            for(int i=n-1;i>=3;i--)
                if(i!=4) printf("%d %d\n",i,n);
            for(int i=0;i<2;i++) printf("%d 4\n",n);
            for(int i=0;i<2;i++) printf("4 2\n");
        }else if(n==4){
            printf("3\n");
            printf("3 4\n");
            for(int i=0;i<2;i++) printf("4 2\n");
        }else{
            printf("2\n");
            for(int i=0;i<2;i++) printf("3 2\n");
        }
    }
    return 0;
}
