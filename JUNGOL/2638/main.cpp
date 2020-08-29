#include<bits/stdc++.h>
using namespace std;
int a[101],d[101];

int main(){
    int n,cnt=0,from=0,cur=0,value;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        while(d[cur]){
            cur = (cur+1)%n;
        }
        d[cur] = a[i];
        cur = (d[cur]+cur) % n;
    }
    printf("%d\n",n);
    for(int i=0;i<n;i++) printf("%d ",d[i]);
    return 0;
}
