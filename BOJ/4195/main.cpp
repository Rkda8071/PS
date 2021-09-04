#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int p[200100],s[200100];
int fin(int x){
    if(p[x] == x) return x;
    return p[x] = fin(p[x]);
}
void uni(int y, int x){
    y = fin(y);
    x = fin(x);
    if(y != x){
        s[y] += s[x];
        p[x] = y;
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        k = 0;
        map<string, int> m;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char a[21],b[21];
            scanf("\n%s %s",a,b);
            if(!m[a]){
                m[a] = ++k;
                s[k] = 1; p[k]=k;
            }
            if(!m[b]){
                m[b] = ++k;
                s[k] = 1; p[k]=k;
            }
            uni(m[a],m[b]);
            printf("[%d %d]\n",fin(m[a]),fin(m[b]));
            printf("%d\n",s[fin(m[a])]);
        }
    }
    return 0;
}
