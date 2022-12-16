#include<bits/stdc++.h>
using namespace std;
int n,m;
int mini = 1;
int l = 1, r, k;
bool solve(){
    for(int i=1;i<n;i++){
        scanf("%d",&k);
        printf("[%d %d %d]",k, i,n);
        l = 1; r = m;
        for(int j=0;j<k;j++){
            int x; char ang;
            scanf("%d %c", &x, &ang);
            printf("%d %c\n",x, ang);
            if(ang == 'L') l = max(l, x+1);
            else r = min(r, x-1);
        }
        if(l<r){
            if(mini > r)
                mini = max(mini,l);
        }else{
            mini = max(mini, r);
        }
        if(mini < r) return false;
    }
    return true;
}
int main(){
    scanf("%d %d",&n,&m);
    printf("%s",solve() ? "YES" : "NO");
    return 0;
}