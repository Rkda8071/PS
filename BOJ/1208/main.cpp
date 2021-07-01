#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[100];
multiset<int> s;

int main(){
    scanf("%d %d",&n,&s);
    int nn = n/2;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(int i=0;i<(1<<nn);i++){ // 1~nn
        int hap=0;
        for(int j=0;j<nn;i++){
            if((i&(1<<j))){
                hap+=a[j];
            }
        }
        s.insert(hap);
    }
    //0~nn-1
    //nn~n-1
    //0~n-nn-1
    for(int i=0;i<(1<<(n-nn));i++){ // nn~n
        int hap=0;
        for(int j=0;j<n-nn;j++){
            if(i&(1<<j)){
                hap+=a[j+nn];
            }
        }
    }
}
