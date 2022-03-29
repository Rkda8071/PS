#include<bits/stdc++.h>
using namespace std;
int a[11][11],dap[11];
int n // <= 1000000000;

int main(){
    scanf("%d",&n);
    int x = 1000000000;
    while(x){
        if(!(n/x)){
            for(int i=1;i<n/x;i++){

            }

        }


        n = n%x;
        x/=10;
    }
}
