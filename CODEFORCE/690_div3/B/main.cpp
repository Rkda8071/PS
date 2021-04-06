#include<bits/stdc++.h>
using namespace std;

int n;
char a[2000];

bool f(){
    if(a[1] == '2'){
        if(a[n-2] == '0' && a[n-1] == '2' && a[n] == '0') return true;
        if(a[2] == '0'){
            if(a[n-1] == '2' && a[n] == '0') return true;
            if(a[3] == '2'){
                if(a[n] == '0') return true;
                if(a[4] == '0') return true;
            }
        }
    }else if(a[n-3] == '2' && a[n-2] == '0' && a[n-1] == '2' && a[n] == '0') return true;
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",a+1);
        printf("%s\n",(f()) ? "YES" : "NO");
    }
    return 0;
}
