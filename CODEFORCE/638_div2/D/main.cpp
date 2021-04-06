#include<bits/stdc++.h>
using namespace std;
int n,d;
int f(int x){

}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<30;i++){
            if((1<<(i+1))-1>=n){
                d = i;
                n -= (1<<i)-1;
            }
        }
    }
}
