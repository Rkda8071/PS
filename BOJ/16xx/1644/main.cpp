#include<bits/stdc++.h>
using namespace std;
int n;
int l,r,hap,dap;
bool chk[4000100];
vector<int> a = {2};

int main(){
    scanf("%d",&n);
    for(int i=3;i<=n;i+=2){
        if(!chk[i]){
            a.push_back(i);
            for(int j=i*3;j<=n;j+=i)
                chk[j] = 1;

        }
    }

    int m=(int)a.size();
    while(1){
        if(hap==n)
            dap++;

        if(hap<n){
            if(r>=m) break;
            hap += a[r++];
        }else{
            hap -= a[l++];
        }
    }
    printf("%d",dap);
}
